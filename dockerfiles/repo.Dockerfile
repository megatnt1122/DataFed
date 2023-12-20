ARG           BUILD_BASE="ubuntu:focal"
ARG         DEPENDENCIES="dependencies"
ARG              RUNTIME="runtime"
ARG          DATAFED_DIR="/datafed"
ARG DATAFED_INSTALL_PATH="/opt/datafed"
ARG            GCS_IMAGE="code.ornl.gov:4567/dlsw/datafed/gcs-ubuntu-focal"
ARG            BUILD_DIR="$DATAFED_DIR/source"
ARG              NVM_DIR="$DATAFED_DIR/.nvm"
ARG              NVM_INC="$DATAFED_DIR/.nvm/versions/node/v13.14.0/include/node"
ARG              NVM_BIN="$DATAFED_DIR/.nvm/versions/node/v13.14.0/bin"
ARG              LIB_DIR="/usr/local/lib"

FROM ${DEPENDENCIES} AS repo-build

ARG DATAFED_DIR
ARG BUILD_DIR
ARG DATAFED_INSTALL_PATH

# This port is needed to communicate with the DataFed core server
EXPOSE 7512
# Not quite sure what 9000 is doing that 7512 isn't, difference between egress
# and ingress?
EXPOSE 9000

COPY ./repository/CMakeLists.txt               ${BUILD_DIR}/repository/CMakeLists.txt
COPY ./CMakeLists.txt                          ${BUILD_DIR}
COPY ./scripts/dependency_versions.sh          ${BUILD_DIR}/scripts/
COPY ./scripts/dependency_install_functions.sh ${BUILD_DIR}/scripts/
COPY ./scripts/generate_datafed.sh             ${BUILD_DIR}/scripts/
COPY ./scripts/generate_repo_config.sh         ${BUILD_DIR}/scripts/
COPY ./scripts/install_repo.sh                 ${BUILD_DIR}/scripts/
COPY ./cmake                                   ${BUILD_DIR}/cmake
COPY ./repository/server                       ${BUILD_DIR}/repository/server

RUN ${BUILD_DIR}/scripts/generate_datafed.sh && \
	cmake -S. -B build						\
	-DBUILD_REPO_SERVER=True		\
	-DBUILD_AUTHZ=False					\
	-DBUILD_CORE_SERVER=False		\
	-DBUILD_WEB_SERVER=False		\
	-DBUILD_DOCS=False					\
	-DBUILD_PYTHON_CLIENT=False	\
	-DBUILD_FOXX=False
RUN cmake --build build
RUN cmake --build build --target install

FROM ${RUNTIME} AS repo

ARG DATAFED_DIR
ARG DATAFED_INSTALL_PATH
ARG BUILD_DIR
ARG LIB_DIR

# The above should also be available at runtime
ENV DATAFED_INSTALL_PATH="$DATAFED_INSTALL_PATH"
ENV          DATAFED_DIR="$DATAFED_DIR"
ENV            BUILD_DIR="$BUILD_DIR"
ENV              LIB_DIR="$LIB_DIR"

WORKDIR /datafed

# copy necessary shared libraries
COPY --from=repo-build /libraries/libprotobuf.so           /libraries/libprotobuf.so
COPY --from=repo-build /libraries/libzmq.so                /libraries/libzmq.so
COPY --from=repo-build /libraries/libsodium.so             /libraries/libsodium.so
COPY --from=repo-build /libraries/libboost_program_options.so /libraries/libboost_program_options.so
COPY --from=repo-build /libraries/libboost_filesystem.so      /libraries/libboost_filesystem.so
RUN ${BUILD_DIR}/scripts/copy_dependency.sh protobuf to
RUN ${BUILD_DIR}/scripts/copy_dependency.sh libzmq to
RUN ${BUILD_DIR}/scripts/copy_dependency.sh libsodium to
RUN ${BUILD_DIR}/scripts/copy_dependency.sh boost_program_options to
RUN ${BUILD_DIR}/scripts/copy_dependency.sh boost_filesystem to

RUN ldconfig

USER datafed

COPY --chown=datafed:root ./repository/docker/entrypoint_repo.sh ${BUILD_DIR}/repository/entrypoint.sh
COPY --chown=datafed:root ./scripts/generate_datafed.sh          ${DATAFED_DIR}/scripts/generate_datafed.sh
COPY --chown=datafed:root ./scripts/generate_repo_config.sh      ${DATAFED_DIR}/scripts/generate_repo_config.sh
COPY --chown=datafed:root ./scripts/install_repo.sh              ${DATAFED_DIR}/scripts/install_repo.sh
COPY --chown=datafed:root ./cmake/Version.cmake                  ${DATAFED_DIR}/cmake/Version.cmake
COPY --from=repo-build --chown=datafed:root ${DATAFED_INSTALL_PATH}/repo/datafed-repo ${DATAFED_INSTALL_PATH}/repo/datafed-repo

ENTRYPOINT ["${BUILD_DIR}/repository/entrypoint.sh"]
CMD ["${DATAFED_INSTALL_PATH}/repo/datafed-repo","--cfg","${DATAFED_INSTALL_PATH}/repo/datafed-repo.cfg"]