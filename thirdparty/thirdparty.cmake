# --------------------------------------------------------------------------------
# Third party dependencies
# --------------------------------------------------------------------------------
set(3rdPartyBlob "${PROJECT_NAME}__3rdPartyBlob")

# --------------------------------------------------------------------------------
# Fetch external
# --------------------------------------------------------------------------------
include(FetchContent)

# Import external libraries using FetchContent.
FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "8.0.1"
  GIT_SHALLOW TRUE
  # EXCLUDE_FROM_ALL TRUE # doesn't work. check
  # https://gitlab.kitware.com/cmake/cmake/-/issues/20167
)
set(FMT_INSTALL ON)
FetchContent_MakeAvailable(fmtlib)
# --------------------------------------------------------------------------------
# Submodules dependencies
# --------------------------------------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/units)
