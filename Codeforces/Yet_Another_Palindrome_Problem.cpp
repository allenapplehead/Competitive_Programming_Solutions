#include <bits/stdc++.h>
using namespace std;

// basically, you read the problem and then realize you only need three numbers to form a palindrome
// those would be either three of the same number or two of the same number that are non-adjacent
// make sure to NEVER use somthing like a == b == c for logic or you will die
// be thorough

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool vis[n + 1];
        vector<int> ar(n);
        memset(vis, false, sizeof(vis));
        string ans = "NO";
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            if (!vis[ar[i]]) {
                vis[ar[i]] = true;
            } else if (i > 0 && (ar[i - 1] != ar[i] || (i > 1 && ar[i - 2] == ar[i - 1] && ar[i - 1] == ar[i]))) {
                ans = "YES";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}