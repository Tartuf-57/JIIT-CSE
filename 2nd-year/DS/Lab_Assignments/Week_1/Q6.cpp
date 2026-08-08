#include <bits/stdc++.h>
using namespace std;

bool isOp(char c) { return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; }
int prec(char c) { return c == '^' ? 3 : (c == '*' || c == '/' ? 2 : (c == '+' || c == '-' ? 1 : -1)); }

string postToPre(string post) {
    stack<string> s;
    for (char c : post) {
        if (isOp(c)) { string o2 = s.top(); s.pop(); string o1 = s.top(); s.pop(); s.push(c + o1 + o2); }
        else s.push(string(1, c));
    }
    return s.top();
}

string preToPost(string pre) {
    stack<string> s;
    for (int i = pre.length() - 1; i >= 0; i--) {
        if (isOp(pre[i])) { string o1 = s.top(); s.pop(); string o2 = s.top(); s.pop(); s.push(o1 + o2 + pre[i]); }
        else s.push(string(1, pre[i]));
    }
    return s.top();
}

string infixToPost(string in) {
    stack<char> s; string res = "";
    for (char c : in) {
        if (c == ' ') continue;
        if (isalnum(c)) res += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') { res += s.top(); s.pop(); }
            if (!s.empty()) s.pop();
        } 
        else {
            while (!s.empty() && prec(s.top()) >= prec(c)) { res += s.top(); s.pop(); }
            s.push(c);
        }
    }
    while (!s.empty()) { res += s.top(); s.pop(); }
    return res;
}

int evalPost(string post) {
    stack<int> s;
    for (char c : post) {
        if (isdigit(c)) s.push(c - '0');
        else {
            int o2 = s.top(); s.pop(); int o1 = s.top(); s.pop();
            if (c == '+') s.push(o1 + o2); else if (c == '-') s.push(o1 - o2);
            else if (c == '*') s.push(o1 * o2); else if (c == '/') s.push(o1 / o2);
            else if (c == '^') s.push(pow(o1, o2));
        }
    }
    return s.top();
}

int main() {
    string post = "AB+C*"; cout << postToPre(post) << endl;
    string pre = "*+ABC"; cout << preToPost(pre) << endl;
    string infix = "(4+9*6)-((8-6)/2*4)*9/3"; 
    string postfix = infixToPost(infix);
    cout << postfix << endl << evalPost(postfix) << endl;
}