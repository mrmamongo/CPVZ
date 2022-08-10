set(build_static_lib ON)
set(lib_utc_datetime ON)
add_subdirectory(third-party/easylogging)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
FetchContent_MakeAvailable(googletest)

set(BUILD_SHARED_LIBS ON)
set(HTTPLIB_REQUIRE_OPENSSL ON)
set(HTTPLIB_REQUIRE_ZLIB ON)
set(HTTPLIB_COMPILE ON)
add_subdirectory(third-party/httplib)

add_subdirectory(third-party/json)