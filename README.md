# Fertile Bed: An opiniated & modern C++ project template

## Introduction

I can't recall how many times I needed to setup a working C++ environment on my machine. It becomes especially difficult when we are not working alone, with other people who are likely to not have the same setup as ours.

This project is meant to serve as a reference for future projects. The idea revolves around the usage of containerized developement environments (or devcontainers) for building, testing and collaborating.

By relying on devcontainers, we can collaborate efficiently on a given project without having to worry about what is the setup of everyone else involved in a given project.

The extra advantage of this approach is that we can ensure we are working in the same exact environment the automated pipelines use during CI/CD execution.

## Setup

To take advantage of these features, we need two things.

### Container Runtime Environment

Any container runtime environment is suitable: [`docker`](https://pages.github.com/), [`podman`](https://pages.github.com/)... This is basically the only thing needed so we can pull container images and run them locally on our machine.

### Integrated Development Environment

The excellent `vscode` IDE has an extension to seamlessly work with devcontainers. This is where the magic happens.
