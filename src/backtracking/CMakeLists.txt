add_library(backtracking_mod OBJECT
    nqueens.cxx
    search_word.cxx
)

target_sources(backtracking_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    nqueens.cxx
    search_word.cxx
)