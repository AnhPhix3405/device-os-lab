#!/bin/bash

# Build script for CI pipeline
set -e

# Install dependencies
sudo apt-get update && sudo apt-get install -y build-essential

# Build all modules
make all
