#include <bits/stdc++.h>
using namespace std;

// solution: realize that the question is just asking you for the number of unique integers
// be careful to READ THE PROBLEM CONSTRAINTS, so I had to use a set instead of a boolean array

set<int> vis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vis.clear();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g;
            cin >> g;
            if (vis.find(g) == vis.end()) {
                vis.insert(g);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}