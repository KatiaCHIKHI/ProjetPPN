# Add an executable for main.cpp
add_executable(main main.cpp)

# Link against the boost_serialization library
target_link_libraries(main boost_serialization)

