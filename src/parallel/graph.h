#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;

typedef pair<string,string> arc;
// type pour la table de hachage (pairs sommet,sommets adjacents)
typedef vector<pair<string,vector<string>>> dict;

class Graph
{ 
    public:
        dict hash_table;
        vector<vector<string>> adj_list;
        Graph(dict ht);
        void printHash();
        void hashToAdjacencyList();
        vector<string> getNeighbors(const string& sommet);
        vector<string> getSommets();
        void addSommet(string s);
        void addArc(string s1, string s2);
        void removeDuplicateNeighbors();
        vector<arc> getArcs();
        vector<string> voisins(string sommet);
        vector<pair<string,int>> calculate_degrees();
        vector<string> degeneracy_ordering();
        Graph find_gj(int j ,vector<string> ordre);
};  

#endif