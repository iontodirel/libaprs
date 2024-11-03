cmake_minimum_required (VERSION 3.8)

project (json_to_cpp VERSION 1.0 LANGUAGES CXX)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
  cmake_policy(SET CMP0135 NEW)
endif()

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt.git GIT_TAG master)
FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
  FetchContent_Populate(fmt)
  add_subdirectory(${fmt_SOURCE_DIR} ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable (json_to_cpp "main.cpp")

set(SYMBOLS_DIR ${CMAKE_SOURCE_DIR}/../../symbols)

set(INPUT_CSV_FILE ${SYMBOLS_DIR}/symbols.csv)
set(OUTPUT_CPP_FILE ${CMAKE_CURRENT_BINARY_DIR}/symbols.cpp)
set(OUTPUT_JSON_FILE ${CMAKE_CURRENT_BINARY_DIR}/symbols.json)
set(OUTPUT_HTML_FILE ${CMAKE_CURRENT_BINARY_DIR}/symbols.html)
set(OUTPUT_JS_FILE ${CMAKE_CURRENT_BINARY_DIR}/symbols.js)

add_definitions(-DOUTPUT_CPP_FILE="${OUTPUT_CPP_FILE}" -DOUTPUT_JSON_FILE="${OUTPUT_JSON_FILE}" -DINPUT_CSV_FILE="${INPUT_CSV_FILE}" -DOUTPUT_HTML_FILE="${OUTPUT_HTML_FILE}" -DOUTPUT_JS_FILE="${OUTPUT_JS_FILE}")
target_link_libraries(json_to_cpp PRIVATE nlohmann_json::nlohmann_json fmt::fmt)

file(DOWNLOAD
    https://raw.githubusercontent.com/ben-strasser/fast-cpp-csv-parser/master/csv.h
    ${CMAKE_SOURCE_DIR}/external/csv.h
)

file(COPY ${SYMBOLS_DIR}/symbols.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

