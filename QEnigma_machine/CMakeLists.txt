cmake_minimum_required(VERSION 3.5)

project(QEnigma_lib LANGUAGES CXX)

find_package(Qt5Core REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB QENIGMA_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

file(GLOB QENIGMA_HEADERS_FILES
        "${PROJECT_SOURCE_DIR}/*.h"
        )


add_library(qenigma SHARED ${QENIGMA_SOURCE_FILES} ${QENIGMA_HEADERS_FILES})

target_link_libraries(qenigma
    PRIVATE
        Qt5::Widgets)

target_include_directories(qenigma
    PUBLIC
        ${PROJECT_SOURCE_DIR})

