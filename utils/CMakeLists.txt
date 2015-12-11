add_library (utils array_utils.cpp binary_search_tree.cpp BoyerMooreFileSearch.cpp)
target_include_directories (utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

