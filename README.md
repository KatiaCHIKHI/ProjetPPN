# max-clique-cpp
Requires cmake 3.14+ and boost serialization library to load datasets

To install boost serialization library:

sudo apt-get install libboost-serialization-dev

## Instructions

To build the main program:

- cmake -S . -B build
- cmake --build build

To launch a quick test with a small graph

- cd build && ctest --verbose

To test with email-Eu-core network dataset (from [here](https://snap.stanford.edu/data/email-Eu-core.html)):

- cd build/src && ./main datasets/email-Eu-core.txt

To test with facebook dataset (from [here](https://snap.stanford.edu/data/ego-Facebook.html)):

- cd build/src && ./main datasets/facebook_combined.txt

## Current goals

- [x] Implement graph representation from the Python code into std::Vector map in C++
- [x] Complete understanding of Bron Kerbosch's algorithm
- [x] Implement max clique functions from the python code into C++
- [x] Test with small graphs
- [x] Implement csv / txt to graph object conversion functionality 
- [ ] Test with full datasets
- [ ] Benchmark the algorithm's performance using full datasets and record results
- [ ] Generate plots from benchmark results
- [ ] Implement parallelism then compare results 
