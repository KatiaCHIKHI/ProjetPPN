#include <iostream>
#include <fstream>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>  
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

#include "BronKerbosch.cpp"


using namespace std;

template<typename T>
void printVector(vector<T> &vec)
{
    for (const auto &item : vec) {
        cout << "{" << item.first << ","
                << item.second << "}" << "; ";
    }
    cout << endl;
}

bool sortPairs(const pair<string, vector<string>> &x, const pair<string, vector<string>> &y)
{
    return stoi(x.first) < stoi(y.first);
}

void graph_load(Graph& g,string filename){
    string line;
    float total = 4031.0;
    // Create and open a text file
    ifstream dataset(filename);

    while (getline (dataset, line)) {
        int pos = line.find_first_of(' ');
        string s1 = line.substr(0,pos), s2 = line.substr(pos+1);
        float p = (stof(s1) * 100.0) / total;
        //show load progress
        cout << "\r" << "Loading graph: " << fixed << setprecision(2) << p << "%" << flush;
        g.addArc(s1,s2);
    }

    cout << endl;

    sort(g.hash_table.begin(),g.hash_table.end(),sortPairs);

    dataset.close();
}

void hash_serlialize(dict hash, string filename)
{
    // Serialize and persist the object (for faster future loading)
    ofstream outfile(filename);
    boost::archive::text_oarchive archive(outfile);
    archive << hash;
}

void hash_deserialize(dict &hash, string filename)
{
    // Deserialize from the file
    ifstream infile(filename);
    boost::archive::text_iarchive extract(infile);
    extract >> hash;
}

int main(){
    Graph g;
    const string filename = "datasets/facebook_combined.txt";
    const string archivename = "datasets/facebook_dict.dat";

    auto start = chrono::high_resolution_clock::now();

    //graph_load(g,filename);

    //hash_serlialize(g.hash_table,archivename);

    hash_deserialize(g.hash_table,archivename);

    g.printHash();

    /* Graph Gj = g.find_gj(0); */

    /* cout << "clique" << endl;
    vector<vector<string>> T;
    for (int j = 0; j < g.getSommets().size(); ++j)
    {
        Graph Gj = g.find_gj(j);
        set<vector<string>> cliques = find_cliques(Gj);
        for (auto k : cliques)
        {
            k = sort_items(k, g.degeneracy_ordering());
            filter_list(T,k);
        }
   
    }
    for (vector<string> s : T)
    {
        cout << "clique" << endl;
        for (string som : s)
        {
            cout << som << endl;
        }
    }  */




    // Get ending timepoint
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
}