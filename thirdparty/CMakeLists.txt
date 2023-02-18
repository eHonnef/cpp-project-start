# --------------------------------------------------------------------------------
# General project settings
# --------------------------------------------------------------------------------
add_library(3rdPartyBlob INTERFACE)
add_library(${namespace}::3rdPartyBlob ALIAS 3rdPartyBlob)

# Including stuff using fetch content
include(./FetchExternal.cmake)

# Including stuff using submodules
add_subdirectory(units)

list(APPEND lst_external units)

target_link_libraries(3rdPartyBlob INTERFACE ${lst_external})
