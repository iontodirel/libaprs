cmake_minimum_required (VERSION 3.8)

project (cvs_to_json VERSION 1.0 LANGUAGES CXX)

add_executable (cvs_to_json "main.cpp")

set(OUTPUT_JSON_FILE ${CMAKE_SOURCE_DIR}/../../symbols.json)


add_definitions(-DOUTPUT_JSON_FILE="${OUTPUT_JSON_FILE}")

file(DOWNLOAD
    https://raw.githubusercontent.com/ben-strasser/fast-cpp-csv-parser/master/csv.h
    ${CMAKE_SOURCE_DIR}/external/csv.h
)

configure_file(${CMAKE_SOURCE_DIR}/../../symbols.csv ${CMAKE_BINARY_DIR}/symbols.csv COPYONLY)
