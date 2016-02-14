project(qt-excercise)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

find_package(Qt5Widgets REQUIRED)

# the easiest way to get Qt working
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 -Wall")

add_subdirectory(plugin_manager_lib)
add_subdirectory(plugin_interfaces_lib)

add_subdirectory(dummy_plugin)
add_subdirectory(static_city_source_plugin)

add_subdirectory(app)

