cmake_minimum_required(VERSION 3.27)
project(csc3380_proj)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(Python 3.10 COMPONENTS Interpreter Development REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(project 
    code/project.cpp
    code/IndicatorBacktestCpp.cpp)

target_include_directories(project PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(project PRIVATE ${Python_LIBRARIES})

set_target_properties(project PROPERTIES INSTALL_RPATH "${Python_LIBRARIES}")
set_target_properties(project PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)