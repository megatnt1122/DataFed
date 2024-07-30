#!/bin/bash

# Get the directory where this script is located
SCRIPT_DIR="$(dirname "$0")"

# Path to the Python script
PYTHON_SCRIPT="${SCRIPT_DIR}/http_server.py"

# Print debugging information
echo "SCRIPT_DIR: ${SCRIPT_DIR}"
echo "PYTHON_SCRIPT: ${PYTHON_SCRIPT}"

# Check if the Python script exists
if [ ! -f "$PYTHON_SCRIPT" ]; then
  echo "Error: $PYTHON_SCRIPT not found"
  exit 1
fi

# Run the Python script
nohup python3 "$PYTHON_SCRIPT" &
