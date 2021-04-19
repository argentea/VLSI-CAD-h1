cmake_minimum_required(VERSION 3.10)
project(hw1)
add_library(${PROJECT_NAME} INTERFACE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(ABC_AIG_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/abc")

target_include_directories(${PROJECT_NAME}
	INTERFACE
	${PROJECT_SOURCE_DIR} ${ABC_AIG_SOURCE_DIR})

add_subdirectory(thirdparty)
add_subdirectory(src)
