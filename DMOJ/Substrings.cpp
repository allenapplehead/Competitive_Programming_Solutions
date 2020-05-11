#include <bits/stdc++.h>
using namespace std;

// LESSONS LEARNED

// use BIG BOI MODS and primes to avoid collisions
// NEVER us a visited array, bitset or w/e rather choose set or sorted array over this
// also unordered_set and set means the difference between tle and ac here
// store big powers that are repeatedly calculated in a variable so you don't need to relcaculate each time

typedef long long ll;
const ll PRIME =    500000000;
const ll MOD =      998244353;

unordered_set<ll> vis;

ll save = -1;

long long fastpow(long long base, long long exp) {
    long long ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret = (ret * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ret % MOD;
}

ll pregen[5005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        ll ans = 0;
        pregen[0] = 0LL;
        // precalculate some values
        for (int i = 0; i < s.length(); ++i) {
            pregen[i + 1] = pregen[i] + fastpow(PRIME, i) * s[i];
        }
        for (int si = 1; si <= s.length(); ++si) {
            ll rabin = 0;
            vis.clear();
            for (int i = 0; i < s.length() - si + 1; ++i) {
                if (i == 0) {
                    rabin = pregen[si];
                } else {
                    rabin -= s[i - 1];
                    if (rabin < 0) rabin += MOD;
                    if (save == -1) save = fastpow(PRIME, MOD - 2) % MOD;
                    rabin *= save;
                    rabin %= MOD;
                    rabin += fastpow(PRIME, si - 1) * (s[i + si - 1]) % MOD; 
                }
                rabin %= MOD;
                //cout << "R: " << rabin << '\n';
                if (vis.find(rabin) == vis.end()) {
                    vis.insert(rabin);
                    ans++;
                }
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}