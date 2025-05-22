#!/bin/env bash

# Environment variables
cat .devcontainer/env_vars.bash | sudo tee -i -a /etc/environment

echo 'alias ctest="ctest --output-on-failure"' >> ~/.bashrc
alias ctest="ctest --output-on-failure"
echo 'alias make="make -j"' >> ~/.bashrc
alias make="make -j"


# Build
mkdir build
mkdir build/test_output

cd build
cmake ..
make


# Software
sudo apt-get -y update
sudo apt-get -y upgrade
sudo apt-get -y install clangd
sudo apt-get -y install pip

pip install --no-input --break-system-packages robotframework
