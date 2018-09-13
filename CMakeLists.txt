cmake_minimum_required(VERSION 3.12)
project(The_C_Programming_Language C)

set(CMAKE_C_STANDARD 99)
set(FILE_NAME 0033_detab)
set(SOURCE_C_LIST Source/${FILE_NAME}.c)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/)

add_executable(${FILE_NAME} ${SOURCE_C_LIST})

install(TARGETS ${FILE_NAME} DESTINATION Build)
