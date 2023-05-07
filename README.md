# Overview


Les graphes non orientés peuvent être utilisés en tant que structures de données qui nous permettent la modélisation des objets ou des problèmes avec de nombreuses applications et utilisations, notamment dans les domaines des réseaux sociaux, des réseaux de transport ou encore les domaines de la biologie. Parmi ces applications se trouve la recherche de structures,On peut par exemple chercher des communautés dans les graphes issus des réseaux sociaux, etc.

Dans notre projet, nous nous intéresserons à la recherche des cliques maximales dans des graphes creux.

Une clique est un sous-graphe du graphe principal comportant des noeuds qui sont tous connectés entre eux.

Le problème d’énumération de cliques maximales ou MCE est parmi les grands problèmes qui existent dans la recherche de cliques, c'est un problème algorithmique qui s'intègre dans le domaine de la théorie des graphes et il consiste à lister toutes les cliques maximales au sein d'un graphe non orienté.




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

To test and compare with facebook dataset (from [here](https://snap.stanford.edu/data/ego-Facebook.html)):

- cd build/src/normal && ./main datasets/facebook_combined.txt | tail -n 1 > ../../../result.txt
- cd ..
- cd parallel && ./mainp datasets/facebook_combined.txt | tail -n 1 >> ../../../result.txt

To test and compare with any other dataset :

- cd build/src/normal && ./main datasets/{yourdataset} | tail -n 1 > ../../../result.txt
- cd ..
- cd parallel && ./mainp datasets/{yourdataset} | tail -n 1 >> ../../../result.txt

To generate comparison plot :

- python compare_results.py

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
