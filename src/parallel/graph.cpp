#include "graph.h"

// fonction pour montrer le progres
void show_loading(int &count, int total, string type)
{
    int p = (count * 100) / total;
    cout << "\r"
         << "Loading " << type << " : " << p << "% " << flush;
    count++;
}

Graph::Graph(dict ht = {})
{
    hash_table = ht;
    sort(hash_table.begin(), hash_table.end());
}

void Graph::printHash()
{
    for (dict::const_iterator it = hash_table.begin(); it != hash_table.end(); ++it)
    {
        cout << (*it).first << " : {";
        for (vector<string>::const_iterator jt = (*it).second.begin(); jt != ((*it).second.end()); ++jt)
        {
            cout << (*jt) << ",";
        }
        cout << "}" << endl;
    }
}

vector<string> Graph::getSommets()
{
    vector<string> sommets;

    for (int i = 0; i < hash_table.size(); i++)
    {
        sommets.push_back(hash_table[i].first);
    }

    return sommets;
};

void Graph::addSommet(string s)
{
    bool exists = false;

    for (const auto& entry : hash_table)
    {
        if (entry.first == s)
        {
            exists = true;
            break;
        }
    }

    if (!exists)
    {
        hash_table.push_back({s, {}});
    }
}

void Graph::addArc(string s1, string s2)
{
    // ajouter les sommets si ils n'existent pas
    addSommet(s1);
    addSommet(s2);

    // coté "s1"
    for (auto& entry : hash_table)
    {
        if (entry.first == s1)
        {
            entry.second.push_back(s2);
        }
        else if (entry.first == s2)
        {
            entry.second.push_back(s1);
        }
    }
}

void Graph::removeDuplicateNeighbors()
{
    // Iterate over each vertex in the hash table
    for (auto& entry : hash_table)
    {
        // Create a set to store unique neighbors
        unordered_set<string> uniqueNeighbors;

        // Iterate over the adjacency list of the current vertex
        // and add neighbors to the set
        for (const auto& neighbor : entry.second)
        {
            uniqueNeighbors.insert(neighbor);
        }

        // Replace the adjacency list of the current vertex with
        // the unique neighbors stored in the set
        entry.second = vector<string>(uniqueNeighbors.begin(), uniqueNeighbors.end());
    }
}

vector<arc> Graph::getArcs()
{
    vector<arc> arcs = {};

    for (int i = 0; i < hash_table.size(); i++)
    {
        // Il faut utiliser des boucles for simples car le parallelisme ne marche pas avec les iterators complexes
        for (int j = 0; j < hash_table[i].second.size(); j++)
        {
            arcs.push_back({hash_table[i].first, hash_table[i].second[j]});
        }
    }

    sort(arcs.begin(), arcs.end());
    return arcs;
}

vector<string> Graph::voisins(string sommet)
{
    vector<string> voisins;
    for (int i = 0; i < hash_table.size(); i++)
    {
        if (hash_table[i].first == sommet)
        {
            voisins = hash_table[i].second;
        }
    }
    return voisins;
}

vector<pair<string, int>> Graph::calculate_degrees()
{

    // vecteur sommets,degrée
    vector<pair<string, int>> degrees = {};
    dict hash = hash_table;

    #pragma omp parallel for
    for (int i = 0; i < hash.size(); i++)
    {
        int degree = hash[i].second.size();
        #pragma omp critical
        {
            degrees.push_back({hash[i].first, degree});
        } 
    }

    // cout << "[calculate_degrees] after loop" << endl;

    sort(degrees.begin(), degrees.end());
    degrees.erase(unique(degrees.begin(), degrees.end()), degrees.end());

    return degrees;
}

vector<string> Graph::degeneracy_ordering()
{
    vector<string> ordering = {};
    // cout << "[degeneracy_ordering] before degrees calculation" << endl;
    vector<pair<string, int>> degrees = calculate_degrees();
    // cout << "[degeneracy_ordering] after degrees calculation" << endl;
    map<string, int> degrees_map;
    copy(degrees.begin(), degrees.end(), inserter(degrees_map, degrees_map.begin()));
    // ordonner le vecteur selon la deuxième valeur
    sort(degrees.begin(), degrees.end(), [](const auto &droite, const auto &gauche)
         { return droite.second < gauche.second; });

    /* 
    int count = 0;
    int total = hash_table.size();
    */
    for (int i = 0; i < degrees.size(); ++i)
    {

        auto somm = degrees[i];
        ordering.push_back((somm).first);

        // show progress
        //show_loading(count, total, "degeneracy ordering");

        vector<string> neighbors = voisins((somm).first);

        for (int j = 0; j < neighbors.size(); j++)
        {
            string s = neighbors[j];
            degrees_map[s]--;
        }
        degrees_map.erase((somm).first);
    }

    //cout << endl;

    return ordering;
}

Graph Graph::find_gj(int j, vector<string> ordre)
{
    Graph gj;
    vector<string> list_voisinage;
    vector<string> Vi;
    vector<string> sommets = getSommets();
    int vertex_order = -1;

    // calcul N[vi]
    list_voisinage = hash_table[j].second;
    list_voisinage.push_back(sommets[j]);

    // calcul Vi
    for (int i = 0; i < ordre.size(); i++)
    {
        if (ordre[i] == sommets[j])
        {
            vertex_order = i;
        }
        if (vertex_order != -1)
        {
            Vi.push_back(ordre[i]);
        }
    }

    // N[vi] inter Vi
    vector<string> intersection;
#pragma omp parallel for shared(intersection) // parallelize the loop
    for (int i = 0; i < list_voisinage.size(); i++)
    {
        for (int j = 0; j < Vi.size(); j++)
        {
            if (list_voisinage[i] == Vi[j])
            {
#pragma omp critical // synchronize access to the shared vector
                {
                    intersection.push_back(list_voisinage[i]);
                }
            }
        }
    }

    // Add vertices to Gj
    for (string v : intersection)
    {
        gj.addSommet(v);
    }

    // ajout des arcs reliants
    vector<string> Sommets_Gj = gj.getSommets();
#pragma omp parallel for shared(gj) // parallelize the loop
    for (int i = 0; i < Sommets_Gj.size(); i++)
    {
        string som = Sommets_Gj[i];
        for (string som_voisin : voisins(som))
        {
            if (find(Sommets_Gj.begin(), Sommets_Gj.end(), som_voisin) != Sommets_Gj.end())
            {
                for (int j = 0; j < gj.hash_table.size(); j++)
                {
                    if (gj.hash_table[j].first == som)
                    {
                        gj.hash_table[j].second.push_back(som_voisin);
                    }
                }
            }
        }
    }

    return gj;
}

vector<string> sort_items(vector<string> items, vector<string> order)
{
    sort(items.begin(), items.end(), [&order](string a, string b)
         { return find(order.begin(), order.end(), a) < find(order.begin(), order.end(), b); });

    return items;
}

bool isContained(const vector<string> &a, const vector<string> &b)
{
    return includes(b.begin(), b.end(), a.begin(), a.end());
}

// Fonction pour ajouter une liste à une liste de listes si elle n'y est pas déjà
void filter_list(vector<vector<string>> &list_of_lists, vector<string> &list_to_add)
{
    if (none_of(list_of_lists.begin(), list_of_lists.end(),
                [&](const vector<string> &current_list)
                { return isContained(list_to_add, current_list); }))
    {
        list_of_lists.emplace_back(list_to_add);
    }
}
