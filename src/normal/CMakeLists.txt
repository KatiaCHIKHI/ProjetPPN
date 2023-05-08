# Add an executable for main.cpp
add_executable(main main.cpp)


# Ajouter des flags d'optimisation
target_compile_options(main PRIVATE -Ofast -march=native)