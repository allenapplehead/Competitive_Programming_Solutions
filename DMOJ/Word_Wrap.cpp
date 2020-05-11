#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 10;
    while(T--) {
        int w;
        cin >> w;
        cin.ignore();
        string s;
        getline(cin, s);
        // tokenise the string
        vector<string> token;
        string cur = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                token.push_back(cur);
                cur = "";
            } else {
                cur += s[i];
            }
        }
        token.push_back(cur);
        // iterate thru the tokens
        int i = 0;
        while (i < token.size()) {
            string cur = "";
            string tok = token[i];
            while (tok.length() > w) {
                cur = tok.substr(0, w);
                tok = tok.substr(w);
                cout << cur << '\n';
            }
            cur = "";
            token[i] = tok;
            while (cur.length() + token[i].length() <= w && i < token.size()) {
                cur += token[i];
                if (i < token.size() - 1) cur += " ";
                ++i;
            }
            cout << cur << '\n';
        }
        cout << "=====" << '\n';
    }
    return 0;
}