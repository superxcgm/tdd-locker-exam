cmake_minimum_required(VERSION 3.15)
project(tdd_locker_exam)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
aux_source_directory(src SRC_FILES)

add_library(tdd_locker_exam SHARED ${SRC_FILES})

add_executable(main main.cpp ${SRC_FILES})

add_subdirectory(test)