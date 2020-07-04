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

## Tasking for PrimaryLockerRobot

1.

Given：PrimaryLockerRobot管理2个M号Locker，第一个Locker没满

When：存包

Then：存包成功，返回票据，包被存入第一个Locker

2.

Given：PrimaryLockerRobot管理2个M号Locker，第一个Locker满了，第二个Locker没满

When：存包

Then：存包成功，返回票据，包被存入第二个Locker

3.

Given：PrimaryLockerRobot管理2个M号Locker，这两个Locker都满了

When：存包

Then：存包失败，提示Locker满了

4.

Given：合法的票据

When：取包

Then：取包成功，取到正确的包

5.

Given：伪造的票据

When：取包

Then：取包失败，提示票据不合法

6.

Given：票据型号不是M

When：取包

Then：取包失败，提示票的型号不对

7.

Given：不是M号的Locker

When：配置PrimaryLockerRobot

Then：提示配置有误

8.

Given：2个PrimaryLockerRobot管理同一个Locker

When：配置PrimaryLockerRobot

Then：提示配置有误



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