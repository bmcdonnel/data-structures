add_executable (remove_list_duplicates remove_list_duplicates.cpp)
add_executable (reverse_linked_list reverse_linked_list.cpp)
add_executable (roman_to_int roman_to_int.cpp)
add_executable (hamming_weight hamming_weight.cpp)
add_executable (majority_element majority_element.cpp)
add_executable (excel_column_number excel_column_number.cpp)
add_executable (has_duplicate has_duplicate.cpp)
add_executable (invert_tree invert_tree.cpp)
add_executable (valid_anagram valid_anagram.cpp)

add_executable (move_zeroes move_zeroes.cpp)
target_include_directories(move_zeroes PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(move_zeroes LINK_PUBLIC utils)

