add_subdirectory(simple)

add_library(tapl INTERFACE)
add_library(tapl::tapl ALIAS tapl)
target_link_libraries(tapl INTERFACE tapl-simple)