cmake_minimum_required(VERSION 3.20)
project(Toaster)

set(CMAKE_CXX_STANDARD 14)

if(APPLE)
    find_package(OpenGL REQUIRED)
    set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/apple)
    set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/apple)
    include_directories(${PROJECT_INCLUDE_DIR})
    link_directories(${PROJECT_LIB_DIR})
else()
    set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/windows)
    set(PROJECT_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/windows)
    include_directories(${PROJECT_INCLUDE_DIR})
    link_directories(${PROJECT_LIB_DIR})
endif()

FILE(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/code/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/code/*.c")
FILE(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/headers/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/src/headers/*.h")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
add_executable(Toaster ${SOURCE_FILES} ${HEADER_FILES})

if(APPLE)
    target_link_libraries(${PROJECT_NAME} glfw3 "-framework Cocoa" "-framework OpenGL" "-framework IOKit")
    add_compile_definitions(APPLE)
else()
    target_link_libraries(${PROJECT_NAME} glfw3 opengl32)
    add_compile_definitions(WINDOWS)
endif()



