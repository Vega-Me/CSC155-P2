cmake_minimum_required(VERSION 3.20)

project(Lab7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Lab7
    main/Lab7.cpp
    ${SOURCES}
)

target_include_directories(Lab7
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)