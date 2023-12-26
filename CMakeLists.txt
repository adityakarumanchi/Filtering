cmake_minimum_required(VERSION 3.25)
project(Filtering)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

enable_testing()
add_executable(Filtering
              GaussianDistribution.hpp
              GaussianDistribution.cpp
              GMMDistribution.hpp
              GMMDistribution.cpp
              test_GaussianDistribution.cpp
              test_GMMDistribution.cpp
              main.cpp)
target_link_libraries(Filtering Eigen3::Eigen GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(Filtering)
