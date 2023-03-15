#include "graph.h"


Graph::Graph(dict ht = {}){
    hash_table = ht;
    sort(hash_table.begin(),hash_table.end());
}

set<string> Graph::getSommets(){
    set<string> sommets;

    for(int i = 0; i < hash_table.size(); i++)
    {   
        //DEBUG: enleve ça quand c'est fini
        cout << hash_table[i].first;
        sommets.insert(hash_table[i].first);
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