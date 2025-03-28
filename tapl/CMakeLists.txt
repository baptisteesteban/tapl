bison_target(parser_simple src/simple/parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(scanner_simple src/simple/lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
add_flex_bison_dependency(scanner_simple parser_simple)

add_library(tapl
    src/simple/ast.cpp
    src/simple/pretty_print.cpp
    src/simple/parse.cpp
    src/simple/is_numerical.cpp
    src/simple/is_value.cpp
    src/simple/eval.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
)
target_include_directories(tapl PUBLIC include ${CMAKE_CURRENT_BINARY_DIR})