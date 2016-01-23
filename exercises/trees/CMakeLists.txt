add_executable (tree_min_depth tree_min_depth.cpp)
target_include_directories(tree_min_depth PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(tree_min_depth LINK_PUBLIC utils)

add_executable (invert_tree invert_tree.cpp)
target_include_directories(invert_tree PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(invert_tree LINK_PUBLIC utils)

add_executable (tree_path_sum tree_path_sum.cpp)
target_include_directories(tree_path_sum PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(tree_path_sum LINK_PUBLIC utils)

add_executable (tree_level_traversal tree_level_traversal.cpp)
target_include_directories(tree_level_traversal PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(tree_level_traversal LINK_PUBLIC utils)

add_executable (binary_tree_paths binary_tree_paths.cpp)
target_include_directories(binary_tree_paths PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(binary_tree_paths LINK_PUBLIC utils)

