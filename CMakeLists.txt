cmake_minimum_required(VERSION 3.20)
project(Toaster)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

include_directories(${PROJECT_INCLUDE_DIR})
link_directories(${PROJECT_LIB_DIR})

FILE(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/code/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/code/*.c")
FILE(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/headers/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/headers/*.h")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(Toaster ${SOURCE_FILES} ${HEADER_FILES} src/code/Shader.cpp)

target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
