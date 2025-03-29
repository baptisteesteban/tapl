bison_target(parser_simple parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(scanner_simple lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_flex_bison_dependency(scanner_simple parser_simple)

add_library(tapl-simple
    ast.cpp
    pretty_print.cpp
    parse.cpp
    is_numerical.cpp
    is_value.cpp
    eval.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
)
add_library(tapl::simple ALIAS tapl-simple)
target_include_directories(tapl-simple PUBLIC ${TAPL_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR})