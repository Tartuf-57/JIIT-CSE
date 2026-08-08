#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    queue<char> q;
    for (char c : s) {q.push(c);}
    while (!q.empty()) {
        char c = q.front();
        int cnt = 0;
        while (q.front() == c) {cnt++; q.pop();}
        cout << c;
        if (cnt > 1) {cout << cnt;}
    }
}