CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project("CPVZ" VERSION 0.0.0.0)
set(TARGET_NAME "cpvz_executable")

option(CPVZ_ENABLE_TESTS "Enable tests" ON)

set(CMAKE_CXX_FLAGS         "")
set(CMAKE_CXX_FLAGS_DEBUG   "")
set(CMAKE_CXX_FLAGS_RELEASE "")

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic")
string(APPEND CMAKE_CXX_FLAGS " -Wconversion -Wunreachable-code -Wuninitialized -Wold-style-cast")
string(APPEND CMAKE_CXX_FLAGS " -Wctor-dtor-privacy -Wnon-virtual-dtor -Wconversion -Wsign-conversion -Winit-self")
string(APPEND CMAKE_CXX_FLAGS " -Wunreachable-code -Wfloat-equal")

string(APPEND CMAKE_CXX_FLAGS " -fPIC")

string(APPEND CMAKE_CXX_FLAGS_DEBUG " -g -Og")
string(APPEND CMAKE_CXX_FLAGS_RELEASE " -O3 -Werror")

add_executable(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/cpvz/dummy.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/logging)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/utils)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/builder)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/controller)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/executor)

#target_link_libraries(${TARGET_NAME}
#        cpvz-builder
#        cpvz-controller
#        cpvz-executor
#)
