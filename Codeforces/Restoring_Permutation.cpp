#include <bits/stdc++.h>
using namespace std;

// bad problem authoring: permutation means numbers from 1 ... n where all numbers 1 to n are included
// greedily try to fill in the answer array with the element itself (as the min) and the next number that has not been visited
// a quick way to check if all numbers 1 - n are there just check if none are greater than n (where im forcing all numbers to be unique)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        vector<int> ans(2 * n);
        set<int> hs;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            ans[i * 2] = ar[i];
            hs.insert(ar[i]);
        }
        // fill in the rest (or try to)
        bool good = true;
        for (int i = 1; i < 2 * n; i += 2) {
            int cur = ans[i - 1];
            while(hs.find(cur) != hs.end()) {
                cur++;
            }
            hs.insert(cur);
            if (cur > 2 * n) {
                good = false;
            }
            ans[i] = cur;
        }
        // check if it is valid
        if (!good) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < 2 * n; ++i) {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}