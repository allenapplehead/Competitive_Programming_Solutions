#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, q, l, r;
        cin >> a >> b >> q;
        ll lcm = (a * b) / __gcd(a, b);
        for (int i = 0; i < q; ++i) {
            cin >> l >> r;
            if (a == 1 && b == 1) {
                cout << 0 << ' ';
                continue;
            }
            ll lower = (l / lcm) * lcm;
            ll upper = (r / lcm) * lcm;
            if (lower + max(a, b) >= l) l = (l / lcm) * lcm;
            if (upper + max(a, b) - 1 >= r) r = (r / lcm) * lcm + max(a, b) - 1;
            ll ans = r - l + 1; // compute both the edges, and then use indirect reasoning
            upper = ((r + lcm - 1) / lcm) * lcm;
            lower = ((l + lcm - 1) / lcm) * lcm;
            ans -= ((upper / lcm - lower / lcm)) * max(a, b);
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}