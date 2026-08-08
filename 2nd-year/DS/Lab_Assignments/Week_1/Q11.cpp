#include <bits/stdc++.h>
using namespace std;

int main() {
    string num; cin >> num;
    int k; cin >> k;
    queue<char> q;
    stack<char> s;
    for (char c : num) {
        q.push(c);
    }
    while (!q.empty()) {
        char curr = q.front(); q.pop();
        while (!s.empty() && k > 0 && s.top() > curr) {
            s.pop(); k--;
        }
        s.push(curr);
    }
    while (!s.empty() && k > 0) {
        s.pop(); k--;
    }
    stack<char> ans;
    while (!s.empty()) {
        ans.push(s.top()); s.pop();
    }
    while (!ans.empty() && ans.top() == '0') {
        ans.pop();
    }
    if (ans.empty()) {
        cout << "0" << endl;
    }
    else {
        while (!ans.empty()) {
            cout << ans.top(); ans.pop();
        }
        cout << endl;
    }
}