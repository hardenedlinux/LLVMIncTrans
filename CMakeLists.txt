
project(trans)
cmake_minimum_required(VERSION 2.8)
#set(PACKAGE_VERSION "")

set(PACKAGE_NAME trans)
set(PACKAGE_STRING "${PACKAGE_NAME}")
set(PACKAGE_BUGREPORT "feqin1023@gmail.com")

set(MAIN_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MAIN_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(src)
#add_subdirectory(test)

# TODO: make and install documentation.
