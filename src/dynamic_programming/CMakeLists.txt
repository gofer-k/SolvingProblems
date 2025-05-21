add_library(dynamic_programming_mod OBJECT
    max_sub_array.cxx
    generate_parenthesis.cxx
)

target_sources(dynamic_programming_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    max_sub_array.cxx
    generate_parenthesis.cxx
)