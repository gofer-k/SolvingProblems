add_library(prefix_sums_mod OBJECT
    prefix_sums.cxx
    sum_sub_array.cxx
)

target_sources(prefix_sums_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    prefix_sums.cxx
    sum_sub_array.cxx 
)