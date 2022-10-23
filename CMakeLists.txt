cmake_minimum_required(VERSION 3.23)
project(C_Introduction C)

set(CMAKE_C_STANDARD 99)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
#配置运行多个main方法 c
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach()