//https://codeforces.com/problemset/problem/1335/E2
#include <bits/stdc++.h>
using namespace std;

// the editorial solution is really clear
// its just that i sucked at implementing it (just use 2 pointers to track where the first block ends and where the last block starts (l and r))
// thus the interval [l, r - 1] will be the middle section (using ps[r - 1] - ps[l])
// and just brute force all possibilities for all numbers

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        vector<vector<int>> cnt(200, vector<int>(n + 1)); // just setting a vector like this creates all elements as 0
        vector<vector<int>> pos(200);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 200; ++j) {
                cnt[j][i + 1] = cnt[j][i]; // for creating it to be a prefix sum array indexed 1 - n inclusive
            }
            cnt[ar[i] - 1][i + 1]++;
            pos[ar[i] - 1].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 200; ++i) {
            ans = max(ans, (int)pos[i].size());
            for (int p = 0; p < (int)pos[i].size() / 2; ++p) {
                int l = pos[i][p] + 1, r = pos[i][(int)pos[i].size() - p - 1] - 1;
                for (int el = 0; el < 200; ++el) {
                    int sum = cnt[el][r + 1] - cnt[el][l]; // the cnt array is 1 indexed, so it is a rsq
                    ans = max(ans, (p + 1) * 2 + sum);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}