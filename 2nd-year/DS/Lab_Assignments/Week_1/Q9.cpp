#include<bits/stdc++.h>
using namespace std;

void moveNthFront(queue<int>& q, int n) {
    queue<int> temp;
    if (n > q.size()) {return;}
    for (int i = 0; i < n-1; i++) {
        temp.push(q.front());
        q.pop();
    }
    q.push(q.front());
    q.pop();
    int left = q.size() - 1;
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
    while (left--) {
        q.push(q.front());
        q.pop();
    }
} 

int main() {
    int sz, n; cin >> sz >> n;
    queue<int> q;
    while (sz--) {
        int temp; cin >> temp;
        q.push(temp);
    }
    moveNthFront(q, n);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}