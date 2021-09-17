cmake_minimum_required(VERSION 3.4.3)

project(test_application)

set(SRC_FILES
    "src/main.cpp"
    "src/program.cpp")

set(SYCL_FILES
    "src/main.cpp")
    
set(HEADER_FILES
    "src/program.h")

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/cmake")

set(ComputeCpp_DIR CACHE STRING "NOT-FOUND")

if (NOT ComputeCpp_DIR)
    message(FATAL_ERROR
    "SYCL implementation root not provided, please specify "
    "the path to the root of the chosen SYCL implementation using "
    "ComputeCpp_DIR=<path/to/install/root>.")
endif()

find_package(ComputeCpp REQUIRED)

add_executable("${PROJECT_NAME}" "${SRC_FILES}" "${HEADER_FILES}")

target_include_directories("${PROJECT_NAME}" PRIVATE 
                           "${ComputeCpp_INCLUDE_DIRS}"
                           "${CMAKE_SOURCE_DIR}/src")

add_sycl_to_target(TARGET "${PROJECT_NAME}"
                   SOURCES "${SYCL_FILES}")
