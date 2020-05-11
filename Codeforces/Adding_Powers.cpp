#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll p = -1;

// read editorial - really simple, U should of figured it out
// make sure to cehck in the end if the array is indeed 0

long long fastpow(long long base, long long exp) {
    long long ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret = (ret * base);
        }
        base = (base * base);
        exp >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> tgt(n);
        string ans = "YES";
        for (int i = 0; i < n; ++i) {
            cin >> tgt[i];
        }
        ll cp = 1;
        for (int i = 0; i < 1000; ++i) {
            if (cp >= 1e16) {
                p = i;
                break;
            } else {
                cp *= k;
            }
        }
        // start from the target and work our way back to 0
        bool flag;
        for (int i = p; i >= 0; --i) {
            flag = false;
            ll curpow = fastpow(k, i);
            //cout << curpow << '\n';
            for (int j = 0; j < n; ++j) {
                if (tgt[j] >= curpow) {
                    if (!flag) {
                        tgt[j] -= curpow;
                        flag = true;
                    } else {
                        ans = "NO";
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (tgt[i] != 0) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}