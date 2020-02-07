cmake_minimum_required(VERSION 3.15)
project(random_pi)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenMP)


add_executable(random_pi main.cpp)
#target_include_directories(random_pi PUBLIC boost_dir )
#target_link_libraries (random_pi PUBLIC boost)