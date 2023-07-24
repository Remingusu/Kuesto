cmake_minimum_required(VERSION 3.25)
project(Kuesto)

set(CMAKE_CXX_STANDARD 17)

########## OpenXLSX ##########
add_subdirectory(external/OpenXLSX)

########## DuckX ##########
add_subdirectory(external/DuckX)

########## SFML ##########
#set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/SFML)
#include_directories(${SFML_DIR}/include)
#set(SFML_LIB sfml-graphics sfml-window)

add_executable(Kuesto main.cpp
        src/files/xlsx_worker.cpp src/headers/xlsx_worker.h
        src/files/docx_generator.cpp src/headers/docx_generator.h
        src/files/interface.cpp src/headers/interface.h)

target_link_libraries(Kuesto OpenXLSX::OpenXLSX duckx) #${SFML_LIB}
