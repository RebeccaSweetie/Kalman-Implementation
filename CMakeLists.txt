cmake_minimum_required(VERSION 3.10)
project(Kalman)

set(CMAKE_CXX_STANDARD 11)

add_executable(EKFtest EKF.cpp)
add_executable(KFtest KF.cpp)

include_directories("/usr/include/eigen3")