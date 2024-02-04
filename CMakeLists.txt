cmake_minimum_required(VERSION 3.25)

project(roman2arabic VERSION 0.1
  DESCRIPTION "converter for roman to arabic numbers"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(PACKAGE_TESTS "Build the tests" ON)
if (PACKAGE_TESTS)
  enable_testing()
  add_subdirectory(external/googletest)
  add_executable(tests tests/unittests.cpp)
  target_include_directories(tests PUBLIC include)
  target_link_libraries(tests gtest_main gmock_main roman2arabiclib)
  include(GoogleTest)
  gtest_discover_tests(tests)
endif()

add_library(roman2arabiclib STATIC src/roman2arabiclib.cpp include/roman2arabiclib/lib.hpp)
target_include_directories(roman2arabiclib PUBLIC include)
target_compile_features(roman2arabiclib PUBLIC cxx_std_20)

target_compile_options(roman2arabiclib PUBLIC -Wall -Wextra -Wpedantic -Werror)

add_executable(roman2arabic apps/roman2arabic.cpp)
target_link_libraries(roman2arabic PUBLIC roman2arabiclib)
