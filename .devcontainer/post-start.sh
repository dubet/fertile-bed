#!/bin/bash

dnf upgrade --assumeyes
dnf install --assumeyes clang clang-tools-extra cmake ninja-build zip unzip tar curl wget vim git tree
