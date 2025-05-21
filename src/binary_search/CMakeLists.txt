add_library(binary_search_mod OBJECT
    minilize_schedule_time.cxx
)

target_sources(binary_search_mod
  PUBLIC
    FILE_SET CXX_MODULES FILES    
     minilize_schedule_time.cxx
)