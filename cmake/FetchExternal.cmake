# --------------------------------------------------------------------------------
# FetchExternal
# --------------------------------------------------------------------------------
include(FetchContent)
# --------------------------------------------------------------------------------
# Import all external libraries using FetchContent.
#
# External dependency example. If your project doesn't have an external
# dependency, remove the line below.
# --------------------------------------------------------------------------------
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "8.0.1"
  GIT_SHALLOW TRUE
  # EXCLUDE_FROM_ALL TRUE # doesn't work. check
  # https://gitlab.kitware.com/cmake/cmake/-/issues/20167
)
set(FMT_INSTALL ON)
# FetchContent_MakeAvailable(fmtlib)
if(NOT fmtlib_POPULATED)
  message(STATUS "Cloning fmtlib")
  FetchContent_Populate(fmtlib)
  add_subdirectory(${fmtlib_SOURCE_DIR} ${fmtlib_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# --------------------------------------------------------------------------------
list(APPEND lst_external fmt::fmt)
