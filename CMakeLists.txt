cmake_minimum_required (VERSION 2.8.3)
project (Tutorial)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(PROGRAMM_NAME "Sort")
set(LIB_NAME "libSort")

get_filename_component(TUTORIAL_MODULE_PATH "./cmake-modules" ABSOLUTE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${TUTORIAL_MODULE_PATH})

find_package(SFML  COMPONENTS system window graphics audio network REQUIRED)
include_directories("src" ${SFML_INCLUDE_DIR})

add_subdirectory(src)


