#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) {cin >> i;}
    queue<int> s;
    for (int i = 0; i < n; i++) {
        s.push(a[i]);
    }
    int num; cin >> num;
    int pos = 0;
    bool found = false;
    bool nxt = false;
    int ans = 0;
    int op = 0;
    while (!s.empty() && op < n) {
        if (!found && s.front() == num) found = true;
        if (found) {
            pos++;
            if (s.front() > num) {
                nxt = true;
                ans = s.front();
                break;
            }
        }
        s.push(s.front());
        s.pop();
        op++;
    }
    if (!found) {cout << "element not found\n";}
    else {
        if (!nxt) {cout << "No next greater element found\n";}
        else {
            cout << "the element " << ans << " is the first next greater element";
            cout << " which is present " << pos << " positions cirularly to the right\n";
        }
    }
}