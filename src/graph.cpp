#include "graph.h"



Graph::Graph(dict ht = {}){
    hash_table = ht;
    sort(hash_table.begin(),hash_table.end());
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
    else
    {
        cout << "Le sommet introduit existe déja dans la table de hachage!" <<endl;
    }

}
 
void Graph::addArc(arc a){
    string s1 = a.first;
    string s2 = a.second;

    //ajouter les sommets si ils n'existent pas
    addSommet(s1);
    addSommet(s2);

    // coté "s1"
    for(int i = 0; i < hash_table.size(); i++)
    {
        if(hash_table[i].first == s1)
        {
            hash_table[i].second.push_back(s2);
        }

        if(hash_table[i].first == s2)
        {
            hash_table[i].second.push_back(s1);
        }
    }

    sort(hash_table.begin(),hash_table.end());

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