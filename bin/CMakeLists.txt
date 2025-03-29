add_executable(eval_simple eval_simple.cpp)
target_link_libraries(eval_simple PRIVATE tapl::simple)

set(install_bin_targets eval_simple)
install(TARGETS ${install_bin_targets} DESTINATION bin)