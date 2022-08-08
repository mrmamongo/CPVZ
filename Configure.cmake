option(CPVZ_ENABLE_TESTS "Enable tests" ON)

set(CMAKE_CXX_FLAGS         "")
set(CMAKE_CXX_FLAGS_DEBUG   "")
set(CMAKE_CXX_FLAGS_RELEASE "")

set(build_static_lib ON)
set(lib_utc_datetime ON)
add_subdirectory(third-party/easylogging)

string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic")
string(APPEND CMAKE_CXX_FLAGS " -Wconversion -Wunreachable-code -Wuninitialized -Wold-style-cast")
string(APPEND CMAKE_CXX_FLAGS " -Wctor-dtor-privacy -Wnon-virtual-dtor -Wconversion -Wsign-conversion -Winit-self")
string(APPEND CMAKE_CXX_FLAGS " -Wunreachable-code -Wfloat-equal")

string(APPEND CMAKE_CXX_FLAGS " -fPIC")

string(APPEND CMAKE_CXX_FLAGS_DEBUG " -g -Og")
string(APPEND CMAKE_CXX_FLAGS_RELEASE " -O3 -Werror")

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