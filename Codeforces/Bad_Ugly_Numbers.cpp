#include <bits/stdc++.h>
using namespace std;

// note

// looked at editorial again 
// basically you spam one 2 and the rest are 3's
// this way you know that if cannot be divided by 2 or 3
// * constructive algos is basically this - finding a proven simple formula

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // spam two and three
        if (n == 1) cout << -1 << '\n';
        else {
            string ans = "2";
            for (int i = 1; i < n; ++i) {
                ans += '3';
            }
            cout << ans << '\n';
        }
    }
    return 0;
}