#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, k;
    long long ans = 0;
    cin >> n >> k;
    vector<long long> a(200005);
    a[0] = 0;
    for (long long t, i = 1; i <= n; i++) {
        cin >> t;
        a[i] = a[i - 1] + t;
    }
    long long c[200005];
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        c[((a[i] % k) + k) % k]++;
    }
    for (int i = 0; i < k; i++) {
        if (c[i] > 1) {
            ans += (c[i] * (c[i] - 1)) >> 1;
        }
    }
    ans += c[0];
    cout << ans << '\n';

    return 0;
}