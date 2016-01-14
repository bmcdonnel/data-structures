add_executable (invert_tree invert_tree.cpp)

add_executable (move_zeroes move_zeroes.cpp)
target_include_directories(move_zeroes PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(move_zeroes LINK_PUBLIC utils)

