#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        string ans = "Yes";
        int lb = c - d;
        int hb = c + d;
        if (n * (a - b) <= hb && n * (a + b) >= lb) {
            cout << ans << '\n';
        } else {
            ans = "No";
            cout << ans << '\n';
        }
    }
    return 0;
}