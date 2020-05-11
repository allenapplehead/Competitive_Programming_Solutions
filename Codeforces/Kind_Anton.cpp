#include <bits/stdc++.h>
using namespace std;

// really elegant implementation once you see if
// basically, you can only match the other array on two conditions
// if you scanned a 1 or -1 strictly before the current idx (allowing u to increment or decrement respectively)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int firstPositive = 1e9;
        int firstNegative = 1e9;
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1 && firstPositive == 1e9) firstPositive = i;
            if (a[i] == -1 && firstNegative == 1e9) firstNegative = i;
        }
        // 0 - determines that the next element will always be what it is
        // 1 - determines that the next element will always increase
        // -1 - determiens that the next will always decrease
        string ans = "YES";
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            if (b[i] > a[i] && firstPositive >= i) {
                ans = "NO";
            } else if (b[i] < a[i] && firstNegative >= i) {
                ans = "NO";
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}