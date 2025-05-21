add_library(bit_manipulation_mod OBJECT
    minimize_binary_operations.cxx
)

target_sources(bit_manipulation_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    minimize_binary_operations.cxx
)