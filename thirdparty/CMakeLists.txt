# --------------------------------------------------------------------------------
# Third party libraries
# --------------------------------------------------------------------------------
add_library(3rdPartyBlob INTERFACE)
add_library(${namespace}::3rdPartyBlob ALIAS 3rdPartyBlob)

# Including stuff using fetch content
include(./FetchExternal.cmake)

# Including stuff using submodules
add_subdirectory(units)

# Append to the list
list(APPEND lst_external units)

# Link to the interface blob
target_link_libraries(3rdPartyBlob INTERFACE ${lst_external})
