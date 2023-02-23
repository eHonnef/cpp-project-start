# --------------------------------------------------------------------------------
# General project settings
# --------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(Colors)
message(STATUS "Using toolchain: ${toolchain}")
# include(toolchains/${toolchain})
include(LTO)
include(Warnings)

project(
  SampleProject # Project name
  VERSION 1.2.3.4 # Project version
  LANGUAGES CXX # Project language
)

set(namespace SampleProject)

# Set the C++ standard and if you are using the C++ extensions
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

# check if this is the main project
set(main_project OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  message(STATUS "+++ This is the main project +++")
  set(main_project ON)
else()
  message(STATUS "+++ Not the main project +++")
endif()

# Enable/disable options (these can be overriden by the command line)
option(
  ENABLE_WARNINGS_SETTINGS
  "Allow target_set_warnings to add flags and defines.
                                 Set this to OFF if you want to provide your own warning parameters."
  ${main_project})
option(enable_lto "Enable link time optimization" ON)
option(
  enable_tests
  "Include tests in the library. Setting this to OFF will remove all doctest related code."
  ${main_project})
option(enable_documentation "Enable the documentation build" OFF)

# --------------------------------------------------------------------------------
# Include cmake stuff
# --------------------------------------------------------------------------------
include(Documentation)
include(Misc)

if(${main_project})
  include(ConfigSafeGuards)
endif()

# Check for LTO support.
find_lto(CXX)

# --------------------------------------------------------------------------------
# locate files
# --------------------------------------------------------------------------------
set(code_dir ${CMAKE_CURRENT_SOURCE_DIR}/code)
set(src_dir ${code_dir}/src)
set(include_dir ${code_dir}/include)

file(GLOB_RECURSE src_files CONFIGURE_DEPENDS "${src_dir}/*.cpp")

# --------------------------------------------------------------------------------
# create libraries
# --------------------------------------------------------------------------------
add_library(${PROJECT_NAME} OBJECT ${src_files})
add_library(${namespace}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC $<BUILD_INTERFACE:${include_dir}>
         $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION})

# --------------------------------------------------------------------------------
# Third party stuff
# --------------------------------------------------------------------------------
# Including the thirdparty deps
add_subdirectory(thirdparty)

# Linking external deps
target_link_libraries(${PROJECT_NAME} PUBLIC 3rdPartyBlob)

# --------------------------------------------------------------------------------
# Main files target
# --------------------------------------------------------------------------------
if(${main_project})
  # Main files
  add_subdirectory(app)

  # Testings
  add_subdirectory(tests)
endif()
