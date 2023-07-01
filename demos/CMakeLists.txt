# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.15)

# Set project name to demos
project(demos VERSION 0.0.1 LANGUAGES CXX)

# Import the libhal-__platform__ library/package (and all of its dependencies)
find_package(libhal-__platform__ REQUIRED CONFIG)

# List of demo applications
# To add a new demo to the list, simply add its filename without the .cpp
# extension to this list.
set(DEMOS blinker)

add_library(startup_code main.cpp)
target_compile_options(startup_code PRIVATE -g)
target_link_libraries(startup_code PRIVATE libhal::__platform__)

foreach(demo IN LISTS DEMOS)
    set(current_project ${demo}.elf)
    message(STATUS "Generating Demo for \"${current_project}\"")
    add_executable(${current_project} applications/${demo}.cpp)
    target_compile_features(${current_project} PRIVATE cxx_std_20)
    target_link_libraries(${current_project} PRIVATE
        startup_code
        libhal::__platform__)
    libhal_post_build(${current_project})
endforeach()
