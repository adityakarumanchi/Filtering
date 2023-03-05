cmake_minimum_required(VERSION 3.20)
project(Filtering)

set(CMAKE_CXX_STANDARD 20)
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

add_executable(Filtering main.cpp GaussianDistribution.hpp GaussianSampler.hpp GMMDistribution.hpp)
target_link_libraries(Filtering Eigen3::Eigen)
