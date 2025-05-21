add_library(sequence_construction_mod OBJECT
    largest_sequence.cxx
)

target_sources(sequence_construction_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
    largest_sequence.cxx
)