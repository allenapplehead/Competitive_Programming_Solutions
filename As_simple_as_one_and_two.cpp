#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<int> r;
        for (string t: {"twone", "one", "two"}) {
            for (size_t pos = 0; (pos = s.find(t, pos)) != string::npos;) {
                s[pos + t.length() / 2] = '?';
                r.push_back(pos + t.length() / 2);
            }
        }
        cout << r.size() << '\n';
        for (auto x : r) {
            cout << x + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}