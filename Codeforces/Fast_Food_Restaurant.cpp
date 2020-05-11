//https://codeforces.com/problemset/problem/1313/A
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> ar(3);
        for (int i = 0; i < 3; ++i) {
            cin >> ar[i];
        }
        int ans = 0;
        // take away 1 dish first
        for (int i = 0; i < 3; ++i) {
            if (ar[i] - 1 >= 0) {
                ar[i]--;
                ans++;
            }
        }
        // take away 2 dishes
        int mx = *max_element(ar.begin(), ar.end());
        int mxidx = max_element(ar.begin(), ar.end()) - ar.begin();
        
        // for the two dishes you make the biggest index suffer the most
        if (ar[mxidx] - 1 >= 0 && ar[(mxidx + 1) % 3] - 1 >= 0) {
            ans++;
            ar[mxidx]--;
            ar[(mxidx + 1) % 3]--;
        }
        if (ar[mxidx] - 1 >= 0 && ar[(mxidx + 2) % 3] - 1 >= 0) {
            ans++;
            ar[mxidx]--;
            ar[(mxidx + 2) % 3]--;
        }

        // see if you can still take the last pair
        if (ar[(mxidx + 1) % 3] - 1 >= 0 && ar[(mxidx + 2) % 3] - 1 >= 0) {
            ar[(mxidx + 1) % 3]--;
            ar[(mxidx + 2) % 3]--;
            ans++;
        }

        // see if we still have enough dishes to remove three
        if (ar[0] > 0 && ar[1] > 0 && ar[2] > 0) {
            ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}