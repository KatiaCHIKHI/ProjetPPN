#include "graph.h"



Graph::Graph(dict ht = {}){
    hash_table = ht;
    sort(hash_table.begin(),hash_table.end());
}

void Graph::printHash(){
    for(dict::const_iterator it = hash_table.begin();it != hash_table.end(); ++it)
    {
        cout << (*it).first << " : {";
        for(vector<string>::const_iterator jt = (*it).second.begin(); jt != ((*it).second.end()); ++jt )
        {
            cout << (*jt) << ",";
        }
        cout << "}" << endl;
    } 
}

vector<string> Graph::getSommets(){
    vector<string> sommets;

    for(int i = 0; i < hash_table.size(); i++)
    {   
        sommets.push_back(hash_table[i].first);
    }

    return sommets;
};

void Graph::addSommet(string s){
    bool exists = false;

    for(int i = 0; i < hash_table.size(); i++)
    {   
        if(hash_table[i].first == s)
        {
            exists = true;
        }
    }

    if(!exists)
    {
        hash_table.push_back({s,{}});
    }

}
 
void Graph::addArc(string s1, string s2)
{
    // ajouter les sommets si ils n'existent pas
    addSommet(s1);
    addSommet(s2);

    // coté "s1"
    for (int i = 0; i < hash_table.size(); i++)
    {
        if (hash_table[i].first == s1)
        {
            hash_table[i].second.push_back(s2);
        }

        if (hash_table[i].first == s2)
        {
            hash_table[i].second.push_back(s1);
        }
    }
}

vector<arc> Graph::getArcs(){
    vector<arc> arcs = {};

    for(int i = 0; i < hash_table.size(); i++)
    {   
        // Il faut utiliser des boucles for simples car le parallelisme ne marche pas avec les iterators complexes 
        for(int j = 0; j < hash_table[i].second.size(); j++)
        {   
            arcs.push_back({hash_table[i].first, hash_table[i].second[j]});
        }   
    }

    sort(arcs.begin(),arcs.end());
    return arcs;

}

vector<string> Graph::voisins(string sommet){
    vector<string> voisins;
    for (auto pair: hash_table){
        if (pair.first == sommet){
            for(string vois:pair.second){
                voisins.push_back(vois);
            }  
        }
    }   
    return voisins;
}


vector<pair<string,int>> Graph::calculate_degrees(){

    //vecteur sommets,degrée
    vector<pair<string,int>> degrees = {};

    auto arc_list = getArcs();

    for(int i = 0; i < arc_list.size(); i++)
    {    
        degrees.push_back({arc_list[i].first,0});
        
        for(int j = 0; j < arc_list.size(); j++)
        {   
            
            if(arc_list[j].first == arc_list[i].first)
            {   
                degrees[i].second += 1;
            }
        }
    }

    sort( degrees.begin(), degrees.end() );
    degrees.erase( unique( degrees.begin(), degrees.end() ), degrees.end() );

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
    //cout << "Graph induit N°" << j << endl;

    Graph gj;
    vector<string> list_voisinage;
    vector<string> Vi;
    vector<string> sommets = getSommets();

    int vertex_order = -1;

    // calcul N[vi]
    list_voisinage = hash_table[j].second;
    list_voisinage.push_back(sommets[j]);
    //cout << "Calcul N[vi] complet" << endl;

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

    //cout << "Calcul Vi complet" << endl;

    // N[vi] inter Vi
    for (string v1 : list_voisinage)
    {
        for (string v2 : Vi)
        {
            if (v1 == v2)
            {
                gj.addSommet(v1);
            }
        }
    }

    //cout << "Calcul N[vi] inter Vi complet" << endl;

    // ajout des arcs reliants
    vector<string> Sommets_Gj = gj.getSommets();
    for (string som : Sommets_Gj)
    {
        for (string som_voisin : voisins(som))
        {
            if (find(Sommets_Gj.begin(), Sommets_Gj.end(), som_voisin) != Sommets_Gj.end())
            {
                for (int i = 0; i < gj.hash_table.size(); i++)
                {
                    if (gj.hash_table[i].first == som)
                    {
                        gj.hash_table[i].second.push_back(som_voisin);
                    }
                }
            }
        }
    }

    //cout << "Ajout des arcs reliants complet" << endl;

    return gj;
}

/// functions used in the main Bron_Kerbosch function
 
vector<string> sort_items(vector<string> items, vector<string> order){
    sort(items.begin(), items.end(), [&order](string a, string b){
        return find(order.begin(), order.end(), a) < std::find(order.begin(), order.end(), b);
    });
    return items;
}


 bool isContained(vector<string>& a, vector<string>& b) {
    return includes(b.begin(), b.end(), a.begin(), a.end());
}

// Fonction pour ajouter une liste à une liste de listes si elle n'y est pas déjà
void filter_list(vector<vector<string>>& list_of_lists, vector<string>& list_to_add) {
    if (!any_of(list_of_lists.begin(), list_of_lists.end(),
            [&](vector<string>& current_list) { return isContained(list_to_add, current_list); })) {
        list_of_lists.push_back(list_to_add);
    }
