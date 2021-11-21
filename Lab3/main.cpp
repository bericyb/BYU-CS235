#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
#include <algorithm>
using namespace std;

int main (int argc, char *argv[]) {
vector<string> bulk;
set<string> unique;
map<string, string> wordmap;
string next_line;
string filename = argv[1];
ifstream inFile(filename);
while (getline(inFile, next_line)){
    istringstream inStream(next_line);
    string token;
    while (inStream >> token) {
        string nopunct = "";
        for (auto &c : token) {
            if (isalpha(c)) {
                nopunct += c;
            }
        }
        bulk.push_back(nopunct);
        unique.insert(nopunct);
    }
}
cout << "Number of words: " << bulk.size() << endl;
cout << "Number of unique words: " << unique.size() << endl;
ofstream outUnique(filename + "_set.txt");
for (set<string>::iterator iter = unique.begin(); iter != unique.end(); ++iter) {
    // cout << " " << *iter << endl;
    outUnique << " " << *iter;
}
ofstream outFile(filename + "_vector.txt");
for (vector<string>::iterator iter = bulk.begin(); iter != bulk.end(); ++iter) {
    // cout << " " << *iter << endl;
    outFile << " " << *iter;
}
string last = "";
for (vector<string>::iterator iter = bulk.begin(); iter < bulk.end(); iter++) {
    wordmap[last] = *iter;
    last = *iter;
}
ofstream outMap(filename + "_map.txt");
for (auto& k : wordmap) {
    outMap << k.first << ", " << k.second << endl;
}


map<string, vector<string>> wordmapTwo;
string current = "";
for (std::vector<string>::iterator iter = bulk.begin(); iter != bulk.end(); iter++) {
    wordmapTwo[current].push_back(*iter);
    current = *iter;
}
// Checking for 6th entry in the word map and then printing all its values.

/*map<string, vector<string>>::iterator bitty = wordmapTwo.begin();
for (int i = 0; i < 6; i++) {
    bitty++;
}
for (int j = 0; j < bitty->second.size(); j++) {
    cout << bitty->second[j] << ", ";
}
cout << endl;
*/

// Checking for Nephi in word map
/*for (map<string, vector<string>>::iterator itty = wordmapTwo.begin(); itty != wordmapTwo.end(); itty++)  {
    if (itty == itty++++++++++++) {
        for(int i = 0; i < itty->second.size(); i++) {
            cout << itty->second[i] << ", ";
        }
        cout  << endl;
    }
*/


map<list<string>, vector<string>> supermap;
list <string> status;
int M = 2;

// Length of Context string.
for (int i = 0; i < M; i++) {
    status.push_back("");
}
// Pushing BULK words between keywords onto supermap with context as keys.

// Get Keywords
string keyWord = "";
list <string> keyList;
string yesNo = "";
cout << "Please enter a keyword..." << endl;
cin >> keyWord;

// Search Bulk for keyword
int keyCount = 0;
for (int y = 0; y < bulk.size(); y++) {
    if (bulk[y] == keyWord) {
        keyCount++;
    }
}
cout << "There are " << keyCount << " references to " << keyWord << "." << endl;
cout << "Continue? y/n" << endl;
cin >> yesNo;

if (yesNo == "y") {
    int start = 0;
    int end = 0;
    int length = 0;
    for (int y = 0; y < bulk.size(); y++) {
        if (bulk[y] == keyWord) {
            start = y;
            for (int i = 0; i < M + 3; i++) {
            keyList.push_back(bulk[y + i]);
            }

            break;
        }
    }
    for (int a = start + 1; a < bulk.size(); a++) {
        if (bulk[a] == keyWord) {
            end = a;
        }
    }

    status.clear();
    for (int i = 0; i < M; i++) {
        status.push_back("");
    }
    for (int o = 0; o < bulk.size(); o++){
        supermap[status].push_back(bulk[o]);
        status.push_back(bulk[o]);
        status.pop_front();
    }

    srand(time(NULL));

    supermap[status].clear();
    if (supermap[status].size() == 0) {cout << "It's clear boiz!" << endl;}

    for (list<string>::iterator ight = keyList.begin(); ight != keyList.end(); ight++) {
        supermap[status].push_back(*ight);
    }
    cout << supermap[status].size() << " This is the size of status in supermap" << endl;
    for (int i = 0; i < supermap[status].size(); i++) {
        cout << supermap[status][i] << endl;
    }

    ofstream IHML (filename + "_final.txt");

    int ind = 1;
      for (int i = 0; i < 500; i++) {

          if (supermap[status].size() != 0){

              ind = rand() % supermap[status].size();
          } else {cout << "It was empty "<< endl;
          ind = 0;}
        IHML << supermap[status][ind]<<" ";
        cout << "bout to push" << ind  << " also this is ind"<< endl;
        status.push_back(supermap[status][ind]);
        cout << "pushed" << endl;
        status.pop_front();
      }
  }
}
