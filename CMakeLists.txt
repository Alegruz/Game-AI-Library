cmake_minimum_required(VERSION 3.0.0)
project(Game-AI-Library VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(CTest)
enable_testing()

add_subdirectory(game_ai_library/machine_learning/cnn)

add_executable(Game-AI-Library main.cpp)

target_link_libraries(Game-AI-Library PUBLIC CNN)

target_include_directories(Game-AI-Library PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/game_ai_library/machine_learning/cnn"
                          )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
