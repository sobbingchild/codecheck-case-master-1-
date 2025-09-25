cmake_minimum_required(VERSION 3.28)
project(codecheck-case)

set(CMAKE_CXX_STANDARD 17)

# 定义一个函数来递归地查找源文件
function(collect_sources DIR SOURCES)
    file(GLOB_RECURSE NEW_SOURCES ${DIR}/*.cpp)
    set(${SOURCES} ${${SOURCES}} ${NEW_SOURCES} PARENT_SCOPE)
endfunction()

# 调用函数来收集 src 目录及其子目录中的所有源文件
set(SOURCE_FILES)
collect_sources(${CMAKE_SOURCE_DIR}/cpp SOURCE_FILES)

# 添加可执行文件
add_executable(codecheck-case ${SOURCE_FILES})


