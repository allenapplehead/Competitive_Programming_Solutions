//https://codeforces.com/contest/1339/problem/C
#include <bits/stdc++.h>
using namespace std;

// find the largest interval and see how long that takes

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        int dif = 0; // find the maximum difference
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            /* find the maximum difference in an array */
            mx = max(mx, ar[i]);
            dif = max(dif, mx - ar[i]);
        }
        if (dif <= 0) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1;
        // see how many seconds it takes to fill in max
        while (pow(2, ans) - 1 < dif) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}