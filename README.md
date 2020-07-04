# Tdd Locker Exam

## Tasking for Locker
1.

Given：Locker有可用容量

When：存包

Then：存包成功，返回票据

2.


Given：Locker满了

When：存包

Then：存包失败，提示Locker满了

3.

Given：票据合法

When：取包

Then：取包成功，拿到正确的包

4.

Given：伪造的票据

When：取包

Then：取包失败，提示票据不合法

5.

Given：和Locker型号不一致的票据

When：取包

Then：取包失败，提示票据型号不对



小樱存包的时候不会犯糊涂，故暂时不考虑存包时检查包大小与Locker是否型号一致。




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