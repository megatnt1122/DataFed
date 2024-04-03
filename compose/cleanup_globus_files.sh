#!/bin/bash
SCRIPT=$(realpath "$0")
SOURCE=$(dirname "$SCRIPT")
PROJECT_ROOT=$(realpath "${SOURCE}/..")

# This script should be run after generating the .env file as it will pull
# values from the .env file

if [ ! -f "${PROJECT_ROOT}/compose/.env" ]
then
  echo "Missing . ${PROJECT_ROOT}/compose/.env file. This file needs to be"
  echo "created first"
  exit 1
fi

. ${PROJECT_ROOT}/compose/.env

export DATAFED_GLOBUS_DEPLOYMENT_KEY_PATH="$DATAFED_HOST_DEPLOYMENT_KEY_PATH"
export DATAFED_GLOBUS_CRED_FILE_PATH="$DATAFED_HOST_CRED_FILE_PATH"

if [ -f "$DATAFED_HOST_CRED_FILE_PATH" ]
then
  export GCS_CLI_CLIENT_ID=$(cat ${DATAFED_HOST_CRED_FILE_PATH}  | jq -r .client)
  export GCS_CLI_CLIENT_SECRET=$(cat ${DATAFED_HOST_CRED_FILE_PATH}  | jq -r .secret)
fi

if [ -f "$DATAFED_GLOBUS_DEPLOYMENT_KEY_PATH" ]
then
  export GCS_CLI_ENDPOINT_ID=$(cat ${DATAFED_GLOBUS_DEPLOYMENT_KEY_PATH}  | jq -r .client_id)
fi

sudo globus-connect-server node cleanup

DATAFED_GCS_ROOT_NAME="$DATAFED_GCS_ROOT_NAME" \
python3 "${PROJECT_ROOT}/scripts/globus/globus_cleanup.py"

#rm -rf "${PROJECT_ROOT}/compose/globus"
