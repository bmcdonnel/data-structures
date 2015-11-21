add_executable (atoi atoi.cpp)

add_executable (reverse_words reverse_words.cpp)
target_include_directories(reverse_words PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries (reverse_words LINK_PUBLIC utils)
