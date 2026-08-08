#include<bits/stdc++.h>
using namespace std;

int main() {
    string str; cin >> str;
    stack<char> s;
    queue<char> q;
    for (char c : str) {
        c = tolower(c);
        s.push(c);
        q.push(c);
    }
    bool poss = true;
    while (!q.empty() && !s.empty()) {
        char a = q.front(); q.pop();
        char b = s.top(); s.pop();
        if (a != b) {poss = false;}
    }
    if (poss) {cout << "Is a pallindrome";}
    else {cout << "Is not a pallindrom";}
}