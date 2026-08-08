#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) {cin >> i;}
    stack<int> s;
    for (int i = n-1; i >= 0; i--) {
        s.push(a[i]);
    }
    int num; cin >> num;
    int pos = 0;
    bool found = false;
    bool nxt = false;
    int ans = 0;
    while (!s.empty()) {
        if (!found && s.top() == num) found = true;
        if (found) {
            pos++;
            if (s.top() > num) {
                nxt = true;
                ans = s.top();
                break;
            }
        }
        s.pop();
    }
    if (!found) {cout << "element not found\n";}
    else {
        if (!nxt) {cout << "No next greater element found\n";}
        else {
            cout << "the element " << ans << " is the first next greater element";
            cout << " which is present " << pos << " positions to the right\n";
        }
    }
}