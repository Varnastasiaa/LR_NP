cmake_minimum_required(VERSION 3.16)
project(LR_NP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NP_app NP.cpp)
if(EXISTS "/opt/homebrew/include")
  target_include_directories(NP_app PRIVATE /opt/homebrew/include)
endif()

enable_testing()

add_executable(np_tests tests/np_tests.cpp)
target_include_directories(np_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
if(EXISTS "/opt/homebrew/include")
  target_include_directories(np_tests PRIVATE /opt/homebrew/include)
endif()

add_test(NAME generate_vector_size COMMAND np_tests generate_vector_size)
add_test(NAME generate_vector_range COMMAND np_tests generate_vector_range)
add_test(NAME sum_groups_basic COMMAND np_tests sum_groups_basic)
add_test(NAME sum_vector_basic COMMAND np_tests sum_vector_basic)
add_test(NAME delete_copy_basic COMMAND np_tests delete_copy_basic)
add_test(NAME sum_index_basic COMMAND np_tests sum_index_basic)
add_test(NAME print_json_basic COMMAND np_tests print_json_basic)
