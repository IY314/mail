cmake_minimum_required(VERSION 3.21)
project(mail)

set(CMAKE_CXX_STANDARD 14)

add_executable(mail main.cpp)
target_include_directories(mail PUBLIC lib/argparse/include)
