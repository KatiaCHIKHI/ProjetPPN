# Add an executable for main.cpp
add_executable(mainp main_parallel.cpp)

# Link against the boost_serialization library
target_link_libraries(mainp boost_serialization)

# Enable OpenMP
find_package(OpenMP REQUIRED)
target_link_libraries(mainp OpenMP::OpenMP_CXX)