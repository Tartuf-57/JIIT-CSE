#include<bits/stdc++.h>
using namespace std;

int solve() {
    string s; 
    getline(cin, s);
    queue<char> q;
    for (char c : s) {
        q.push(c);
    }  
    int len = s.length();
    int idx = 0;
    while (idx < len) {
        char c = q.front();
        int cnt = 0;

        for (int i = 0; i < len; i++) {
            if (q.front() == c) {
                cnt++;
            }
            q.push(q.front());
            q.pop(); 
        }
        if (cnt == 1) { 
            return idx;
        }
        q.push(q.front());
        q.pop();
        idx++;
    } 
    return -1;
}

int main() {
    int ans = solve();
    cout << ans << endl;
    return 0;
}