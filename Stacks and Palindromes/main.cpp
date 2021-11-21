#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main (){
    string trypal("this is a palap a si sht");

    stack<char> checkr;
    for(int i = 0; i < trypal.length(); i++) {
        checkr.push(trypal[i]);
    }
    bool ispal = true;
    for(int i = 0; i < trypal.length(); i++) {
        char next = checkr.top();
        checkr.pop();
        cout << "Comparing " << trypal[i] << " " << next << endl;
        if(trypal[i] != next) {
            cout << "NOTTT" << endl;
            ispal = false;
            break;
        }
    }

    if (ispal) {
        cout << "It is!" << endl;
    }
}
