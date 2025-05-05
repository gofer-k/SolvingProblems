cmake_minimum_required(VERSION 3.28)

project(problem_solving)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS=ON)

# This necessarily with GCC 14 onward
# analyze the time taken to compile each module
set(CMAKE_CXX_FLAGS "-fmodules-ts -ftime-report")

# Specify the path to the installed library
set(CMAKE_PREFIX_PATH "/home/useme/develoment/dev/cpp_samples/user_utilities")
find_package(UserUtilities REQUIRED)

add_library(sum_sub_array_lib)

target_sources(sum_sub_array_lib
  PUBLIC
    FILE_SET CXX_MODULES FILES
    # implemation needs is suffic 'cxx', 'cpp'
      src/generate_parenthesis.cxx
      src/minilize_schedule_time.cxx
      src/minimize_binary_operations.cxx
      src/non_overlapping_intervals.cxx
      src/nqueens.cxx
      src/prefix_sums.cxx
      src/rotation_cases.cxx
      src/sum_sub_array.cxx 
      src/search_word.cxx    
      )
      
target_link_libraries(sum_sub_array_lib
  # UserUtilities
  )

add_executable(problem_solving src/main.cpp)

target_link_libraries(problem_solving 
  sum_sub_array_lib
  # UserUtilities
  )

