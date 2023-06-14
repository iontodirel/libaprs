cmake_minimum_required (VERSION 3.8)

project (cvs_to_html VERSION 1.0 LANGUAGES CXX)

add_executable (cvs_to_html "main.cpp")

set(OUTPUT_HTML_FILE ${CMAKE_SOURCE_DIR}/../../../symbols.html)
set(INPUT_JSON_FILE ${CMAKE_SOURCE_DIR}/../../../symbols.csv)

add_definitions(-DOUTPUT_HTML_FILE="${OUTPUT_HTML_FILE}" -DINPUT_JSON_FILE="${INPUT_JSON_FILE}")

file(DOWNLOAD
    https://raw.githubusercontent.com/ben-strasser/fast-cpp-csv-parser/master/csv.h
    ${CMAKE_SOURCE_DIR}/external/csv.h
)
