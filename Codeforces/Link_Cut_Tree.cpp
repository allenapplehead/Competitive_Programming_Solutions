#include <bits/stdc++.h>
using namespace std;

// notice that the exponent can't get really large or else it breaks the boundaries of the problem
// so just brute force it

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long l, r, k;
    cin >> l >> r >> k;
    
    string ans = "";
    for (int i = 0; i < 1000000; ++i) {
        long long prod = pow(k, i);
        if (prod >= l && prod <= r) {
            ans += to_string(prod);
            ans += ' ';
        }
        if (prod > r) break;
    }
    if (ans.length() == 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}