project("CPVZ - Utils" VERSION 0.0.0.0)
set(TARGET_NAME "cpvz-utils")

add_library(${TARGET_NAME} OBJECT
        ${CMAKE_CURRENT_SOURCE_DIR}/src/modules/linux/module.cpp
)

target_link_libraries(${TARGET_NAME}
    cpvz-logging
)

target_include_directories(${TARGET_NAME}
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (CPVZ_ENABLE_TESTS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
endif ()
