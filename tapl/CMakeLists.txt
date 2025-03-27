flex_target(scanner_simple src/simple/lexer.ll ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)

add_executable(lexer_simple ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)

add_library(tapl
    src/simple/ast.cpp
    src/simple/pretty_print.cpp    
)
target_include_directories(tapl PUBLIC include)