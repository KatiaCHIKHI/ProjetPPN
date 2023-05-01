# max-clique-cpp
Requires cmake 3.14+
Requires cmake 3.14+ and boost serialization library to load datasets

To install boost serialization library:

sudo apt-get install libboost-serialization-dev


## Instructions
To launch small tests:
- cmake -S . -B build
- cmake --build build
- cd build && ctest --verbose

To test with facebook dataset:
- cd src
- g++ main.cpp -o main -lboost_serialization
- ./main


## Current goals
- [x] Implement graph representation from the Python code into std::Vector map in C++
- [x] Complete understanding of Bron Kerbosch's algorithm
- [X] Implement max clique functions from the python code into C++
- [x] Test with small graphs
- [X] Implement csv / txt to graph object conversion functionality 
- [ ] Test with full datasets 
- [ ] Benchmark the algorithm's performance using full datasets and record results
- [ ] Generate plots from benchmark results
- [ ] Implement parallelism then compare results 

 
