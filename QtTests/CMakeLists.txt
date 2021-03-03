cmake_minimum_required(VERSION 3.5)

project(QtTests LANGUAGES CXX)

find_package(Qt5Core REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

set(SOURCE_DIR ${PROJECT_SOURCE_DIR})

set(ENIGMA_DIR "../Enigma_machine")
set(QENIGMA_DIR "../QEnigma_machine")

include_directories(${SOURCE_DIR})

include_directories(${ENIGMA_DIR})
include_directories(${QENIGMA_DIR})

add_executable(${PROJECT_NAME} test.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Test
    PUBLIC
        enigma
        qenigma)

