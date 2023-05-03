#include <gtest/gtest.h>
#include <fstream> 
#include "../src/bron_kerbosch.cpp"

using namespace std;


dict graph_elements{
        {"1", {"2", "3"}},
        {"2", {"1", "3"}},
        {"3", {"1", "2", "4"}},
        {"4", {"3"}}
};

Graph g(graph_elements);

vector<string> degen_order = g.degeneracy_ordering();

TEST(MainTest, HashTable)
{
    EXPECT_EQ(g.hash_table,graph_elements);
}

TEST(MainTest, AddGetSommets)
{
    g.addSommet("10");

    auto s = g.getSommets();

    cout << endl;

    // Afficher les sommets
    cout << "sommets : [";
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ",";
    }
    cout << "]" << endl;

}

TEST(MainTest, AddGetArc)
{
    g.addArc("10","11");

    auto arcs = g.getArcs();

    // Afficher les arcs
    cout << "arcs : [";
    for(auto it = arcs.begin(); it != arcs.end(); it++)
    {
        cout << "{"<< it->first << "," << it->second << "},";
    }
    cout << "]" << endl;
}

TEST(MainTest, CalculateDegrees)
{
    auto degrees = g.calculate_degrees();

    // Afficher les degrees de chaque sommets
    cout << "degrees : [";
    for(auto it = degrees.begin(); it != degrees.end(); it++)
    {   
        cout << "{'"<< it->first << "', " << it->second << "}";
    }
    cout << "]" << endl;
}

TEST(MainTest, DegeneracyOrdering)
{
    auto dg = g.degeneracy_ordering();

    // Afficher degeneracy ordering
    cout << "degeneracy ordering : [";
    for(auto it = dg.begin(); it != dg.end(); it++)
    {   
        cout << "{'"<< *it <<"'}";
    }
    cout << "]" << endl;
}


TEST(MainTest, FindGj)
{   
    // Afficher Graphe Gj avec j=0
    Graph gj = g.find_gj(0,degen_order);
    

    cout << endl;
    cout << " Graphe Gj avec j = 0" << endl;
    for(pair<string,vector<string>> element: gj.hash_table){
         cout<< "sommet:" << " " << element.first << " ";
         cout<< "voisins:" << " "  ;
         for(string s:element.second){
            cout<< s << " ";
         } 
         cout << endl;
    }

     // Afficher Graphe Gj avec j=1
    gj = g.find_gj(1,degen_order);
    

    cout << endl;
    cout << " Graphe Gj avec j = 1" << endl;
    for(pair<string,vector<string>> element: gj.hash_table){
         cout<< "sommet:" << " " << element.first << " ";
         cout<< "voisins:" << " "  ;
         for(string s:element.second){
            cout<< s << " ";
         } 
         cout << endl;
    }

     // Afficher Graphe Gj avec j=2
    gj = g.find_gj(2,degen_order);
    

    cout << endl;
    cout << " Graphe Gj avec j = 2" << endl;
    for(pair<string,vector<string>> element: gj.hash_table){
         cout<< "sommet:" << " " << element.first << " ";
         cout<< "voisins:" << " "  ;
         for(string s:element.second){
            cout<< s << " ";
         } 
         cout << endl;
    }

     // Afficher Graphe Gj avec j=3
    gj = g.find_gj(3,degen_order);
    

    cout << endl;
    cout << " Graphe Gj avec j = 3" << endl;
    for(pair<string,vector<string>> element: gj.hash_table){
         cout<< "sommet:" << " " << element.first << " ";
         cout<< "voisins:" << " "  ;
         for(string s:element.second){
            cout<< s << " ";
         } 
         cout << endl;
    }
}

TEST(MainTest, FindClique)
{
    set<vector<string>> cliques = find_cliques(g);

    for(auto c: cliques)
    {
        cout << "{";
        for(auto u: c)
        {
            cout << u << ", ";
        }
        cout << "}" << endl;
    }

}

TEST(MainTest, main)
{
    bron_kerbosch(g,degen_order);
}

