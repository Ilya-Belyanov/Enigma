cmake_minimum_required(VERSION 3.5)

project(Enigma_lib LANGUAGES CXX)

file(GLOB ENIGMA_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

file(GLOB ENIGMA_HEADERS_FILES
        "${PROJECT_SOURCE_DIR}/*.h"
        )
		
add_library(enigma SHARED ${ENIGMA_SOURCE_FILES} ${ENIGMA_HEADERS_FILES})

target_include_directories(enigma
    PUBLIC
        ${PROJECT_SOURCE_DIR})
