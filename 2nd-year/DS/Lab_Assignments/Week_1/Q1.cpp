#include<bits/stdc++.h>
using namespace std;

bool good (char a, char b) {
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return true;
    return false;
}

bool open (char a) {
    if (a == '(' || a == '[' || a == '{') return true;
    return false;
}


int main () {
    string s; cin >> s;
    stack<char> st;

    bool poss = true;
    for (char c : s) {
        if (open(c)) st.push(c);
        else {
            if (!st.empty() && good(st.top(),c)) {
                st.pop();
            }
            else {
                poss = false; break;
            }
        }
    }
    if (!poss || !st.empty()) {
        cout << "Is not a regular bracket sequence\n";
    }
    else {
        cout << "Is a regular bracket sequence\n";
    }
}