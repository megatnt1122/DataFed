#!/bin/bash

# Entrypoint for running gcs should be in root
# To run it just pass in /entrypoint.sh as an argument
set -euf -o pipefail

if [ -n "$UID" ]; then
    OLD_ID=$(su datafed -c "id -u")
    usermod -u $UID datafed
    find /datafed -uid "$OLD_ID" -exec chown -h "$UID" {} + >/dev/null 2>&1
    find /opt/datafed -uid "$OLD_ID" -exec chown -h "$UID" {} + >/dev/null 2>&1
fi


SCRIPT=$(realpath "$0")
SOURCE=$(dirname "$SCRIPT")
PROJECT_ROOT=$(realpath ${SOURCE}/../..)
# Translate datafed env variables to globus env variables
GLOBUS_CLIENT_ID="$DATAFED_GLOBUS_APP_ID"
${PROJECT_ROOT}/scripts/generate_datafed.sh
${BUILD_DIR}/scripts/globus/setup_globus.sh

log_path="$DATAFED_DEFAULT_LOG_PATH"

if [ ! -d "${log_path}" ]
then
  su -c "mkdir -p ${log_path}" datafed
fi

su datafed -c '"$@"' -- argv0 "$@"
