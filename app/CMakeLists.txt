cmake_minimum_required(VERSION 3.14)

# ------------------------------------------------------------------------------------------------------------
# Add an executable for the main files app/main.cpp. If you add more
# executables, copy these lines accordingly.
add_executable(main Main.cpp) # Name of exec. and location of file.
# Link the executable to library (if it uses it). I added the lst_external here
# to be available in the main file (you can remove)
target_link_libraries(main PRIVATE ${namespace}::${PROJECT_NAME}
                                   ${lst_external})
target_set_warnings(
  main
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
  TARGET main
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different ${file_to_copy} $<TARGET_FILE_DIR:main>)
# ------------------------------------------------------------------------------------------------------------
