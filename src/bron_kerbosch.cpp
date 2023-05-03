#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "graph.cpp"

using namespace std;

// fonction générique pour afficher un vecteur de vecteurs
template <typename T>
void print_vector(const vector<T>& vec)
{
    cout << "Vector contents: ";
    for (const auto& element : vec)
    {
        cout << "{ ";
        for (const auto& sub_element : element)
        {
            cout << sub_element << " ";
        }
        cout << "} ";
        cout << endl;
    }
}

set<string> intersection(set<string> v1, set<string> v2)
{

    set<string> v3;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.end()));

    return v3;
}

set<string> difference(set<string> v1, set<string> v2)
{

    set<string> v3;

    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.end()));

    return v3;
}

set<string> v_union(set<string> v1, set<string> v2)
{

    set<string> v3;

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.end()));

    return v3;
}

void find_cliques_pivot(dict &hash, set<string> r, set<string> p, set<string> x, set<vector<string>> &cliques)
{
    if (p.empty() && x.empty())
    {
        cliques.emplace(r.begin(), r.end());
    }
    else
    {
        string u = *(p.empty() ? x.begin() : p.begin());
        set<string> hash_set;
        for (int i = 0; i < hash.size(); i++)
        {
            if (hash[i].first == u)
            {
                vector<string> k = hash[i].second;

                hash_set.insert(k.begin(), k.end());
            }
        }

        for (string v : difference(p, hash_set))
        {
            set<string> neighs;
            for (int i = 0; i < hash.size(); i++)
            {
                if (hash[i].first == v)
                {
                    vector<string> k = hash[i].second;
                    neighs.insert(k.begin(), k.end());
                }
            }
            find_cliques_pivot(hash, v_union(r, {v}), intersection(p, neighs), intersection(x, neighs), cliques);
            p.erase(v);
            x.insert(v);
        }
    }
}

set<vector<string>> find_cliques(Graph g)
{

    dict hash = g.hash_table;
    vector<string> sommets = g.getSommets();
    set<string> p(sommets.begin(), sommets.end());
    set<string> r;
    set<string> x;
    set<vector<string>> cliques;
    vector<string> degen_order = g.degeneracy_ordering();

    for (const string &v : degen_order)
    {
        set<string> neighs;
        for (int j = 0; j < hash.size(); j++)
        {
            if (hash[j].first == v)
            {
                vector<string> k = hash[j].second;
                neighs.insert(k.begin(), k.end());
            }
        }
        find_cliques_pivot(hash, v_union(r, {v}), intersection(p, neighs), intersection(x, neighs), cliques);
        p.erase(v);
        x.insert(v);
    }

    return cliques;
}

vector<vector<string>> bron_kerbosch(Graph g)
{
    vector<vector<string>> T;

    vector<string> degen_order = g.degeneracy_ordering();

    cout << "Ordre de dégénérescence du graphe principal calculé." << endl;

    int sommets_size = g.getSommets().size();

    cout << "Calcul de cliques maximales à partir des graphes induits:" << endl;
    for (int j = 0; j < sommets_size; ++j)
    {
        Graph Gj = g.find_gj(j, degen_order);

        cout << "\r                Graphe induit : " << j << " / " << sommets_size << "         " << flush;

        set<vector<string>> cliques = find_cliques(Gj);
        int count = 1;
        int total = cliques.size();

        for (vector<string> k : cliques)
        {

            k = sort_items(k, degen_order);
            filter_list(T,k);
            //print_vector(T);
            int p = (count * 100) / total;
            cout << "\r"
                 << "Loading subgraphs " << " : " << p << "% " << flush;
            count++;
        } 
        
    }

    cout << endl;

    for (vector<string> s : T)
    {
        cout << "clique : {";
        for (string som : s)
        {
            cout << som << ", ";
        }
        cout << "}" << endl;
    }

    return T;
}

