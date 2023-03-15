#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
        Graph(dict ht);
        set<string> getSommets();
        void addSommet(string s);
        void addArc(arc a);
        vector<arc> getArcs();
        vector<pair<string,int>> calculate_degrees();
        vector<string> degeneracy_ordering();
        void degeneracy();
        Graph find_gj();
};  

#endif