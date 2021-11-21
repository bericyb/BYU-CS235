#include <map>
#include <string>
#include <sstream>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;

int main() {
    // Create a map with a list of strings as key and vector of strings as values.
    map<list<string>, vector<string>> wordMap;
    list<string> keyList;
    vector<string> valueVector;
    //Reading in text file.
    string filename = "";
    string parse;
    cout << "Enter the filename you would like to use: ";
    cin >> filename;
    cout << "Enter a keyword you would like to use: ";
    cin >> keyWord;
    ifstream textFile (filename);

    //Parse text into vector.
    while (getline(textFile, parse)) {
        istringstream stream(parse);
        string bulk = "";
        while (stream >> bulk) {
            string nopunc = "";
            for (auto & c : bulk)  {
                if (isalpha(c)) {
                    nopunc += c;
                }
            }
            valueVector.push_back();
        }
    }
    // Ask for context value
    int M = 1;
    cout <<  "How much context do you want to use? (default is 1)" << endl;
    cin >> M;

    //  Searching for keyword and find length of talk.
    //Make context initial list with keyword
    cout << "Searching for keywords..." << endl;
    for (int i = 0; i < valueVector.size(); i++) {
        if (valueVector[i] == keyWord) {
            for (i; i < i + M; i++) {
                keyList.push_back(valueVector[i]);
            }
        }
    }





    return 0;
}
