# README

`gcc` playground to quickly test new compilers and features.

## building and running

1. build docker container: `./build_docker.sh`
2. build and run executable: `./run.sh`

## update compiler

1. update base image of Dockerfile (`FROM gcc:<desired version>`)
2. re-build docker container
3. build and run executable

## alternative without docker

Download compiler from pre-build compiler-explorer versions and move the extracted folder to
`/opt/compiler_explorer/`. E.g.

```bash
$ curl -L https://compiler-explorer.s3.amazonaws.com/opt/clang-17.0.1.tar.xz | tar Jx
$ `mkdir /opt/compiler_explorer/`
$ `mv <extracted_compiler> /opt/compiler_explorer/`
```

Many other compilers are available (e.g. `gcc-13.1.0.tar.xz`). A complete list can be obtained as
described [here](https://github.com/compiler-explorer/infra/blob/main/docs/installing_compilers.md).

Build binary with complete path to the downloaded compiler and either link to respective standard
library, or set library path manually when running the program:

```bash
# linking to lib
$ /opt/compiler_explorer/gcc-13.1.0/bin/g++ -std=c++23 -L /opt/compiler_explorer/gcc-13.1.0/lib64 main.cpp -o main.out && ./main.out
# set library manually
$ /opt/compiler_explorer/gcc-13.1.0/bin/g++ -std=c++23 main.cpp -o main.out && export LD_LIBRARY_PATH=/opt/compiler_explorer/gcc-13.1.0/lib64/ && ./main.out
```
