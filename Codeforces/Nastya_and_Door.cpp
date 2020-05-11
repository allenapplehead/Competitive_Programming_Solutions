#include <bits/stdc++.h>
using namespace std;

// used simple sliding windows algorithm to solve
// tricky to implement because a peak is determined by its neighbors as well

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        // peaks happen where at a value at an idx it is bigger than the values on both sides strictly
        int mx = 0;
        // intialize the sliding window
        bool peak[n];
        memset(peak, false, sizeof(peak));
        for (int i = 1; i < k - 1; ++i) {
            if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
                mx++;
                peak[i] = true;
            }
        }
        // look for the rest
        int cur = mx;
        pair<int, int> ans = {cur, 0};
        for (int i = k - 1; i < n - 1; ++i) {
            if (peak[i - k + 2]) {
                cur--;
            }
            if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
                cur++;
                peak[i] = true;
            }
            if (cur > mx) {
                mx = cur;
                ans = make_pair(mx, i - (k - 1) + 1);
            }
        }
        cout << ans.first + 1 << " " << ans.second + 1 << '\n';
    }
    return 0;
}