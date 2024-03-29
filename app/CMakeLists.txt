cmake_minimum_required(VERSION 3.25)

# ------------------------------------------------------------------------------------------------------------
# Add an executable for the main files app/main.cpp. If you add more
# executables, copy these lines accordingly.
set(target_name main)
add_executable(${target_name} Main.cpp) # Name of exec. and location of file.

# Dependencies
add_dependencies(${target_name} SampleProject::SampleProject)

# Link the executable to library (if it uses it).
target_link_libraries(${target_name} PRIVATE SampleProject::SampleProject)
target_set_warnings(
  ${target_name}
  ENABLE
  ALL
  AS_ERROR
  ALL
  DISABLE
  Annoying) # Set warnings (if needed).
target_enable_lto(main optimized) # enable link-time-optimization if available
                                  # for non-debug configurations

set(file_to_copy "${CMAKE_CURRENT_LIST_DIR}/../LICENSE")

add_custom_command(
  TARGET ${target_name}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${file_to_copy}
          $<TARGET_FILE_DIR:main>)
# ------------------------------------------------------------------------------------------------------------
