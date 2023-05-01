#include <gtest/gtest.h>
#include "../src/graph.cpp"

using namespace std;

dict graph_elements{
        {"1", {"2", "3"}},
        {"2", {"1", "3"}},
        {"3", {"1", "2", "4"}},
        {"4", {"3"}}
    };

Graph g(graph_elements);

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
    g.addArc({"10","11"});

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
    auto gj = g.find_gj(1);
    auto s = gj.getSommets();

    cout << endl;

    // Afficher les sommets gj
    cout << "sommets gj : [";
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << ",";
    }
    cout << "]" << endl;

    auto arcs = gj.getArcs();

    // Afficher les arcs gj
    cout << "arcs : [";
    for(auto it = arcs.begin(); it != arcs.end(); it++)
    {
        cout << "{"<< it->first << "," << it->second << "},";
    }
    cout << "]" << endl;
}