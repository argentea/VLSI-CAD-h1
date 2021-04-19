project(equivalencelib)
file(GLOB SOURCES
        src/*.cpp
        src/*.cc
        src/*.c)
set(INCLUDE_DIRS 
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../..
  ${ABC_AIG_SOURCE_DIR}
  )
include_directories(${INCLUDE_DIRS})
add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_executable(equivalence equivalence.cpp)
target_include_directories(equivalence PUBLIC ${INCLUDE_DIRS})
target_link_libraries(equivalence PUBLIC ${PROJECT_NAME} abc)
