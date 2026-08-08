#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b; 
    cout << "Enter number in base 10: "; cin >> n;
    cout << "Enter the base to change to (2-9): "; cin >> b;
    stack<int> s;
    while (n > 0) {
        s.push(n%b);
        n/=b;
    }
    cout << n << " in base " <<  b << " is: ";
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}
