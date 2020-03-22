#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    // 2 pointer
    a[0] = 0;
    long long l = 0, r = 0;
    long long ans = 0;
    while (l <= n && r <= n) {
        if (a[r] - a[l] < m) {
            ans = max(ans, r - l);
            r++;
        } else {
            l++;
        }
    }
    cout << ans << '\n';
    return 0;
}