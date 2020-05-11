#include <bits/stdc++.h>
using namespace std;

// notes

// read editorial

int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

map<int, int> dict;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        dict.clear();
        int n;
        cin >> n;
        vector<int> ar(n);
        vector<int> ans(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            for (int j = 0; j < 11; ++j) {
                if (ar[i] % primes[j] == 0) {
                    ans[i] = j + 1;
                    if (dict.find(j + 1) == dict.end()) {
                        dict.insert(make_pair(j + 1, cur));
                        cur++;
                    }
                    break;
                }
            }
        }
        // now make sure every colour is used
        cout << cur - 1 << '\n';
        for (int i = 0; i < n; ++i) {
            cout << dict.at(ans[i]) << ' ';
        }
        cout << '\n';
        
    }
    return 0;
}