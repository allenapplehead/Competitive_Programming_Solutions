#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string in;
    vector<string> all;
    int tgt;
    cin >> in >> tgt;
    for (int i = 0; i <= (int)in.length() - tgt; i++) {
        all.push_back(in.substr(i, 4));
    }
    sort(all.begin(), all.end());
    for (auto s : all) {
        cout << s << endl;
    }
    cout << all[0] << "\n";
    return 0;
}