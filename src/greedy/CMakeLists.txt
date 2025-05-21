add_library(greedy_mod OBJECT
    non_overlapping_intervals.cxx
    rotation_cases.cxx
)

target_sources(greedy_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    non_overlapping_intervals.cxx
    rotation_cases.cxx 
)