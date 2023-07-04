# README

gcc playground to quickly test new compilers and features.

## building and running

1. build docker container: `./build_docker.sh`
2. build and run executable: `./run.sh`

## update compiler

1. update base image of Dockerfile (`FROM gcc:<desired version>`)
2. re-build docker container
3. build and run executable
