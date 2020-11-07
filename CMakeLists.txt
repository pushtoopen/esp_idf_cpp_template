# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
# this is setup for ESP-EDF 4.1 or above
cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17) #C++ standard 17 requires cmake 3.8 min

set(EXTRA_COMPONENT_DIRECTORIES main application) #for main, this may be unnecessary for standard esp-idf, if you change the main folder to another name, rename this along with it. This IS required for the application folder.

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(esp_cpp_template) #change this when you use this template somwhere else.
