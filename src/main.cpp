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

#include "bron_kerbosch.cpp"

using namespace std;

bool sortPairs(const pair<string, vector<string>> &x, const pair<string, vector<string>> &y)
{
    return stoi(x.first) < stoi(y.first);
}

int getNbrLines(string filename)
{
    // Create and open a text file
    ifstream file(filename);

    int count = 0;

    string lines;
    while (getline(file, lines))
    {
        count++;
    }

    return count;
}

void graph_load(Graph &g, string filename)
{
    // Create and open a text file
    ifstream dataset(filename);

    if (!dataset.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
    }
    else
    {   
        string line;

        int total = getNbrLines(filename);
        int count = 0;

        while (getline(dataset, line))
        {
            int pos = line.find_first_of(' ');
            string s1 = line.substr(0, pos), s2 = line.substr(pos + 1);
            int p = (count * 100) / total;
            // show load progress
            show_loading(count, total, "dataset");
            g.addArc(s1, s2);
        }

        cout << endl;

        sort(g.hash_table.begin(), g.hash_table.end(), sortPairs);

        dataset.close();
    }
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

int main(int argc, char* argv[])
{
    Graph g;
    //const string filename = "datasets/email-Eu-core.txt";
    //const string archivename = "datasets/facebook_dict.dat";

    // Check if the correct number of command-line arguments is passed
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    // Get the file path from the command-line argument
    string filename = argv[1];

    // Open the file
    ifstream file(filename);
    

    auto start = chrono::high_resolution_clock::now();

    graph_load(g,filename);

    // hash_serlialize(g.hash_table,archivename);

    // hash_deserialize(g.hash_table, archivename);

    g.printHash();

    bron_kerbosch(g);

    // Get ending timepoint
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " milliseconds" << endl;
}