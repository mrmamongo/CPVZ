CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("CPVZ" VERSION 0.0.0.0)
set(TARGET_NAME "cpvz_executable")

include(Libraries.cmake)
include(Configure.cmake)

#add_executable(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/cpvz/dummy.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/logging)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/utils)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/builder)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/controller)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpvz/executor)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/server)


#target_link_libraries(${TARGET_NAME}
#        cpvz-builder
#        cpvz-controller
#        cpvz-executor
#)
