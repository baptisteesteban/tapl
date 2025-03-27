find_package(GTest REQUIRED)

function(my_add_test test_name)
    set(nt test_${test_name})

    add_executable(${nt} ${test_name}.cpp)
    target_link_libraries(${nt} PRIVATE tapl GTest::Main)
    add_test(NAME ${nt} COMMAND ${nt})
    set_target_properties(${nt} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
    set_tests_properties(${nt} PROPERTIES LABELS UnitTests)
endfunction(my_add_test)

my_add_test(simple)