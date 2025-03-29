set(TAPL_BUILD_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/tapl TYPE INCLUDE)

add_subdirectory(src)

set(install_lib_targets tapl-simple)
install(TARGETS ${install_lib_targets} DESTINATION lib)