# Tdd Locker Exam



## Build

### Prerequisite
1. cmake INSTALLED
2. conan INSTALLED

### Build
```shell script
# install dependency
cd test
mkdir build && cd build
conan install ..

# build
cd ../..
mkdir cmake-build-debug && cd cmake-build-debug 
cmake .. && cmake --build .

# run test
./test/tests
```