cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

enable_testing()
include(./build/conan_paths.cmake)

find_package(Threads REQUIRED)
find_package(gtest REQUIRED)
include_directories(${GTest_INCLUDE_DIRS})

aux_source_directory(. TEST_FILES)
add_executable(tests ${TEST_FILES})

target_link_libraries(tests tdd_locker_exam ${GTest_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})