cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp branch.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Village ${SOURCES})

target_include_directories(Village PUBLIC ${MY_INCLUDE_DIR})