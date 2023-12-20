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

FROM ${GCS_IMAGE}

ARG DATAFED_DIR
ARG BUILD_DIR
ARG DATAFED_INSTALL_PATH

RUN mkdir -p ${BUILD_DIR}
RUN mkdir -p ${BUILD_DIR}/logs
RUN mkdir -p ${BUILD_DIR}/common/proto
RUN mkdir -p ${DATAFED_INSTALL_PATH}/authz
RUN mkdir -p ${DATAFED_DIR}/collections/mapped

RUN apt update
RUN apt install -y vim netcat

# For communicating with public
EXPOSE 443

# Needed for Globus GridFTP communication
EXPOSE 50000-51000

WORKDIR ${BUILD_DIR}

RUN adduser --disabled-password --gecos "" datafed

RUN echo "#!/bin/bash\n\$@" > /usr/bin/sudo && chmod +x /usr/bin/sudo

COPY ./scripts/dependency_versions.sh          ${BUILD_DIR}/scripts/
COPY ./scripts/dependency_install_functions.sh ${BUILD_DIR}/scripts/
COPY ./scripts/install_authz_dependencies.sh   ${BUILD_DIR}/scripts/

RUN DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC ${BUILD_DIR}/scripts/install_authz_dependencies.sh

ARG rebuild=true
ARG DATAFED_DIR
ARG BUILD_DIR
ARG DATAFED_INSTALL_PATH

ENV GCS_COLLECTION_ROOT_PATH="$DATAFED_DIR/collections/mapped"
ENV     DATAFED_INSTALL_PATH="$DATAFED_INSTALL_PATH"
ENV	             DATAFED_DIR="$DATAFED_DIR"
ENV                BUILD_DIR="$BUILD_DIR"


# All files should be owned by the datafed user
RUN chown -R datafed:datafed ${DATAFED_DIR}

COPY --chown=datafed:root ./scripts/dependency_versions.sh        ${BUILD_DIR}/scripts/
COPY --chown=datafed:root ./scripts/generate_authz_config.sh      ${BUILD_DIR}/scripts/generate_authz_config.sh
COPY --chown=datafed:root ./scripts/generate_datafed.sh           ${BUILD_DIR}/scripts/generate_datafed.sh
COPY --chown=datafed:root ./CMakeLists.txt                        ${BUILD_DIR}
COPY --chown=datafed:root ./cmake                                 ${BUILD_DIR}/cmake
COPY --chown=datafed:root ./repository/CMakeLists.txt             ${BUILD_DIR}/repository/CMakeLists.txt
COPY --chown=datafed:root ./repository/gridftp/CMakeLists.txt     ${BUILD_DIR}/repository/gridftp/CMakeLists.txt
COPY --chown=datafed:root ./scripts/globus/setup_globus.sh        ${BUILD_DIR}/scripts/globus/setup_globus.sh
COPY --chown=datafed:root ./scripts/globus/generate_repo_form.sh  ${BUILD_DIR}/scripts/globus/generate_repo_form.sh
COPY --chown=datafed:root ./repository/docker/entrypoint_authz.sh ${BUILD_DIR}/repository/docker/entrypoint_authz.sh
COPY --chown=datafed:root ./common                                ${BUILD_DIR}/common
COPY --chown=datafed:root ./repository/gridftp/globus5            ${BUILD_DIR}/repository/gridftp/globus5

# Build as if a non root user
USER datafed

RUN ${BUILD_DIR}/scripts/generate_datafed.sh

RUN ${BUILD_DIR}/scripts/generate_authz_config.sh &&	\
	cmake -S. -B build				\
		-DBUILD_REPO_SERVER=False		\
		-DBUILD_AUTHZ=True			\
		-DBUILD_CORE_SERVER=False		\
		-DBUILD_WEB_SERVER=False		\
		-DBUILD_DOCS=False			\
		-DBUILD_PYTHON_CLIENT=False		\
		-DBUILD_FOXX=False
RUN cmake --build build
RUN cmake --build build --target install

COPY ./scripts/globus/setup_globus.sh        ${BUILD_DIR}/scripts/globus/setup_globus.sh
COPY ./scripts/globus/generate_repo_form.sh  ${BUILD_DIR}/scripts/globus/generate_repo_form.sh
COPY ./repository/docker/entrypoint_authz.sh ${BUILD_DIR}/repository/docker/entrypoint_authz.sh

USER root

WORKDIR ${DATAFED_INSTALL_PATH}/authz