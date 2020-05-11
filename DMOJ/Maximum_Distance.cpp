#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int ans = 0, res = 0, l = 0, r = 0;
        while (l < n && r < n) {
            while (l > r) r++;
            if (a[l] <= b[r]) {
                if(!res) {
                    res = r - l - 1;
                }
                res++;
                r++;
            } else {
                res = 0;
                l++;
            }
            ans = max(ans, res);
        }
        cout << "The maximum distance is " << ans << '\n';
    }
    return 0;
}