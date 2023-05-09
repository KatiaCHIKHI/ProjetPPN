# Overview


Undirected graphs can be used as data structures that allow us to model objects or problems with many applications and uses, notably in the fields of social networks, transportation networks or even biology. Among these applications is the search of structures, we can for example search for communities in graphs from social networks, etc.

In our project, we are interested in finding maximal cliques in sparse graphs.

A clique is a subgraph of the main graph with nodes that are all connected to each other.

The maximal clique enumeration problem or MCE is one of the major problems in clique search, it is an algorithmic problem that fits in the field of graph theory and it consists in listing all maximal cliques within an undirected graph.




# max-clique-cpp

(LINUX ONLY)

Requires cmake 3.14+ and OpenMP runtime library (for parallelization).

Plot generation requires Python 3 (with the packages numpy and matplotlib)

To install the OpenMP runtime library:

`sudo apt-get install libomp-dev`

## Instructions

To build both the normal and paralellized programs:

- cmake -S . -B build
- cmake --build build

To launch a quick test with a small graph

- cd build && ctest --verbose

To test and compare results with email-Eu-core network dataset (from [here](https://snap.stanford.edu/data/email-Eu-core.html)):

- cd build/src/normal && ./main datasets/email-Eu-core.txt | tail -n 1 > ../../../result.txt
- cd ..
- cd parallel && ./mainp datasets/email-Eu-core.txt | tail -n 1 >> ../../../result.txt

To test and compare with any other dataset :

- cd build/src/normal && ./main datasets/{yourdataset} | tail -n 1 > ../../../result.txt
- cd ..
- cd parallel && ./mainp datasets/{yourdataset} | tail -n 1 >> ../../../result.txt

To generate comparison plot :

- python compare_results.py

To generate plots using a script file

- gnuplot 'script_name.sh'

## Current goals

- [x] Implement graph representation from the Python code into std::Vector map in C++
- [x] Complete understanding of Bron Kerbosch's algorithm
- [x] Implement max clique functions from the python code into C++
- [x] Test with small graphs
- [x] Implement csv / txt to graph object conversion functionality 
- [x] Test with full datasets
- [x] Benchmark the algorithm's performance using full datasets and record results
- [x] Generate plots from benchmark results
- [x] Implement parallelism then compare results 
