#include <bits/stdc++.h>
using namespace std;

// look at my previous solution:
// just print all the array differences that are not the k maximum differences (BIG BRAIN)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    vector<pair<int, int>> diff(n - 1);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (i > 0) {
            diff[i - 1].first = ar[i] - ar[i - 1];
            diff[i - 1].second = i; 
        }
    }

    // just find the splitting points, which are the maximum splitting points
    sort(diff.rbegin(), diff.rend());
    
    // tokenize the original array accordingly
    vector<int> splits;
    for (int i = 0; i < k - 1; ++i) {
        splits.push_back(diff[i].second);
    }
    sort(splits.begin(), splits.end());

    int ctr = 0, last = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ctr == splits.size()) {
            ans += ar[n - 1] - ar[last];
            break;
        }
        if (i == splits[ctr]) {
            ans += ar[i - 1] - ar[last];
            last = i;
            ctr++;
        }
    }
    cout << ans << '\n';
    return 0;
}