project("CPVZ - Logging" VERSION 0.0.0.0)
set(TARGET_NAME "cpvz-logging")

add_library(${TARGET_NAME} OBJECT
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cpp
)

find_package(Boost REQUIRED COMPONENTS log)

target_link_libraries(${TARGET_NAME}
    Boost::log
)

target_include_directories(${TARGET_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (CPVZ_ENABLE_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif ()
