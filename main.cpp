#include <bits/stdc++.h>
using namespace std;

//temp testing
//read every line of csv file into vector of strings
vector<string> readCSV(string filename)
{
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

int main()
{
    //call readCSV("test.csv") and print the vector
    vector<string> lines = readCSV("tmdb_5000_movies.csv");
    for (int i = 0; i < 20; i++)
    {
        cout << lines[i] << endl;
    }

    return 0;
}