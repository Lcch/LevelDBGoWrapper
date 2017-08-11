
# LevelDBGoWrapper

LevelDBGoWrapper is a Go wrapper for [LevelDB](https://github.com/google/leveldb). It also demonstrates a way to bind C++ codes at Golang programs, which is leverage on cgo and swig.

## Setup
* Install leveldb:

  leveldb is a submodule as this repo. You are able to install leveldb by following commands:
  ```
  > git submodule update --init
  > cd leveldb
  > make
  ```

* Install swig:

  swig is able to easily be installed by apt-get or brew install.

* How to bind leveldb to LevelDBGoWrapper

  - Firstly install leveldb which will generate include files and shared-lib. Put these to ```/usr/local/include``` and ```/usr/local/lib``` to make gcc/g++ to be able to find leveldb library easier.
  - Write wrapper file like ```leveldb_interface.*``` is c++ wrapper function which is going to expose to golang function. Swig compiles our c++ programs with leveldb library and generate its binding go-code ```leveldbwrapperlib.go``` and ```leveldbwrapper_wrap.cxx```.
  - ```lib.go``` is to indicate package name of wrapper.
  - ```leveldbwrapperlib.i``` is swig file to indicate what functions is it going to expose to golang.
  - To generate binding codes, following command ```swig -go -cgo -c++ -intgosize 64 leveldbwrapperlib.i```

  - Make our wrapper link leveldb at runtime. Add a line
  ```#cgo LDFLAGS: -lleveldb``` just right ahead of ```import "C"```

* Test and Benchmark
  * simple test:

    run ```go run cmd/main.go```, it works when it shows ```elsa```
