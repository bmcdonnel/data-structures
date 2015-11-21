add_library (sort merge_sort.cpp quick_sort.cpp)

target_include_directories (sort PUBLIC ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (sort_stuff main.cpp)

target_link_libraries (sort_stuff LINK_PUBLIC sort utils)

