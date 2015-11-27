add_executable (atoi atoi.cpp)
add_executable (factorial_zeroes factorial_zeroes.cpp)

add_executable (reverse_words reverse_words.cpp)
target_include_directories(reverse_words PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (reverse_words LINK_PUBLIC utils)

add_executable (find_kth_smallest find_kth_smallest.cpp)
target_include_directories(find_kth_smallest PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (find_kth_smallest LINK_PUBLIC utils)

