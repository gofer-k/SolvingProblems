cmake_minimum_required(VERSION 3.28)

project(problem_solving LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-fmodules-ts")

# This necessarily with GCC 14 onward
# analyze the time taken to compile each module
# set(CMAKE_CXX_FLAGS "-ftime-report")

# Specify the path to the installed library
set(CMAKE_PREFIX_PATH "/home/useme/develoment/dev/cpp_samples/user_utilities")
find_package(UserUtilities REQUIRED)

add_subdirectory(src/backtracking)
add_subdirectory(src/dynamic_programming)
add_subdirectory(src/greedy)
add_subdirectory(src/prefix_sums)
add_subdirectory(src/binary_search)
add_subdirectory(src/bit_manipulation)
# add_subdirectory(src/sequence_construction)

add_executable(problem_solving src/main.cpp)

target_link_libraries(problem_solving 
  backtracking_mod
  binary_search_mod
  bit_manipulation_mod
  dynamic_programming_mod
  greedy_mod
  prefix_sums_mod
  # sequence_construction_mod
  # UserUtilities
)

