add_executable (min_depth min_depth.cpp)
target_include_directories(min_depth PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(min_depth LINK_PUBLIC utils)

add_executable (invert_tree invert_tree.cpp)
target_include_directories(invert_tree PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(invert_tree LINK_PUBLIC utils)

add_executable (path_sum path_sum.cpp)
target_include_directories(path_sum PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(path_sum LINK_PUBLIC utils)

add_executable (leaf_paths leaf_paths.cpp)
target_include_directories(leaf_paths PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(leaf_paths LINK_PUBLIC utils)

add_executable (traversals traversals.cpp)
target_include_directories(traversals PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(traversals LINK_PUBLIC utils)

