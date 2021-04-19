project(tautologylib)
file(GLOB SOURCES
        src/*.cpp
        src/*.cc
        src/*.c)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_executable(tautology tautology.cpp)
target_link_libraries(tautology PUBLIC ${PROJECT_NAME})
