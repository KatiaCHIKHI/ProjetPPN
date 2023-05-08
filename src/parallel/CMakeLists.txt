# Add an executable for main.cpp
add_executable(mainp main_parallel.cpp)

# Enable OpenMP
find_package(OpenMP REQUIRED)
target_link_libraries(mainp OpenMP::OpenMP_CXX)

# Ajouter des flags d'optimisation
target_compile_options(mainp PRIVATE -Ofast -march=native)