add_library(tapl
    src/simple/ast.cpp
    src/simple/pretty_print.cpp    
)
target_include_directories(tapl PUBLIC include)