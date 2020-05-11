#include <bits/stdc++.h>
using namespace std;

bool isOperator (char x) {
    switch(x) {
        case '+':
        case '-':
            return true;
    }
    return false;
}

string solve(string pre_exp) {
    stack<string> s;
    int length = pre_exp.length();
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(pre_exp[i])) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + " " + op2 + " " + pre_exp[i];
            s.push(temp);
        } else if (pre_exp[i] != ' ') {
            s.push(string(1, pre_exp[i]));
        }
    }
    return s.top();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    stack<char> converter;
    string in;
    getline(cin, in);
    while (in != "0") {
        string ans = solve(in);
        cout << ans << '\n';
        getline(cin, in);
    }
    return 0;
}