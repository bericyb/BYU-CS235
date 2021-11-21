#include <iostream>
#include <stack>
#include <string>

using namespace std;

const string OPEN = "([{";
const string CLOSE = ")]}";



bool is_open(char ch) {
    cout << OPEN.find(ch) << "open found" <<endl;
    return OPEN.find(ch) != string::npos;
}
bool is_close(char ch) {
    cout << CLOSE.find(ch) << "close found" << endl;
    return CLOSE.find(ch) != string::npos;
}

stack<char> s;

int main () {

const string expression = "(([]{()}))";


bool balanced = true;
for (string::const_iterator iter = expression.begin();
    balanced && (iter != expression.end()); iter++) {
        char next_ch = *iter;
        if (is_open(next_ch)) {
            s.push(next_ch);
        } else if (is_close(next_ch)) {
            if (s.empty()) {
                balanced = false;
                cout << "nah" << endl;
            } else {
                char top_ch = s.top();
                s.pop();
                balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
            }
        }
    }
    cout << balanced << endl;
    return balanced && s.empty();
}
