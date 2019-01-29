project(1 CXX)

set(CMAKE_CXX_FLAGS "-std=c99 -Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s")

add_executable(project1 main.cpp)