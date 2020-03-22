#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string a[n];
    string b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    set<pair<string, string>> pairs;
    for (int i = 0; i < n; ++i) {
        // pair them up
        if (a[i] == b[i]) {
            cout << "bad" << '\n';
            return 0;
        } else {
            string s[2];
            s[0] = a[i];
            s[1] = b[i];
            sort(s, s + 2);
            pairs.insert(make_pair(s[0], s[1]));
        }
    }
    if (pairs.size() == n / 2) {
        cout << "good" << '\n';
    } else {
        cout << "bad" << '\n';
    }
    return 0;
}