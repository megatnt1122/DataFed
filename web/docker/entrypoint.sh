#!/bin/bash

# NVM_DIR must be defined

set -euf -o pipefail

SCRIPT=$(realpath "$0")
SOURCE=$(dirname "$SCRIPT")
PROJECT_ROOT=$(realpath ${SOURCE}/../..)

${PROJECT_ROOT}/scripts/generate_datafed.sh
${PROJECT_ROOT}/scripts/generate_ws_config.sh
${PROJECT_ROOT}/scripts/install_ws.sh
${PROJECT_ROOT}/scripts/dependency_versions.sh

export NVM_DIR="${DATAFED_DEPENDENCIES_INSTALL_PATH}/nvm"
export NODE_VERSION="$DATAFED_NODE_VERSION"
[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh" # This loads nvm

# Send output to file as well as print to terminal
log_path=$(grep "log-path" /datafed/install/web/datafed-ws.cfg | cut -d "=" -f 2 | tr -d ' ')

if [ ! -d "${log_path}" ]
then
  mkdir -p "${log_path}"
fi

if [ "$#" -eq 0 ]; then
  echo "No arguments were passed, running bash"
  exec "bash"
  exit 0
fi

datafed_ws_exec=$(basename "$1")
if [ "${datafed_ws_exec}" = "datafed-ws.js" ]
then
  # Send output to log file
  "$@"  2>&1 | tee "$log_path/datafed-ws.log"
else
  echo "Not sending output to datafed-ws.log"
  # If not do not by default send to log file
  exec "$@"
fi
