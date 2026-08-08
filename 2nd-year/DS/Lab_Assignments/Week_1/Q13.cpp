#include <bits/stdc++.h>
using namespace std;

int main() {
    string pre; cin >> pre;
    stack<int> st;
    for (int i = pre.length() - 1; i >= 0; i--) {
        if (isdigit(pre[i])) st.push(pre[i] - '0');
        else {
            int o1 = st.top(); st.pop(); int o2 = st.top(); st.pop();
            if (pre[i] == '+') st.push(o1 + o2);
            else if (pre[i] == '-') st.push(o1 - o2);
            else if (pre[i] == '*') st.push(o1 * o2);
            else if (pre[i] == '/') st.push(o1 / o2);
            else if (pre[i] == '^') st.push(pow(o1, o2));
        }
    }
    cout << st.top() << endl;
}