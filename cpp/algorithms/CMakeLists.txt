add_executable (atoi atoi.cpp)
add_executable (factorial_zeroes factorial_zeroes.cpp)

add_executable (reverse_words reverse_words.cpp)
target_include_directories(reverse_words PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (reverse_words LINK_PUBLIC utils)

add_executable (find_kth_smallest find_kth_smallest.cpp)
target_include_directories(find_kth_smallest PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (find_kth_smallest LINK_PUBLIC utils)

add_executable (shuffle shuffle.cpp)
target_include_directories(shuffle PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (shuffle LINK_PUBLIC utils)

add_executable (bst_node_path bst_node_path.cpp)
target_include_directories(bst_node_path PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (bst_node_path LINK_PUBLIC utils)

add_executable (beat_the_market beat_the_market.cpp)
target_include_directories(beat_the_market PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (beat_the_market LINK_PUBLIC utils)

add_executable (grep grep.cpp)
target_include_directories(grep PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (grep LINK_PUBLIC utils)

add_executable (maximal_subarray maximal_subarray.cpp)
target_include_directories(maximal_subarray PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (maximal_subarray LINK_PUBLIC utils)

