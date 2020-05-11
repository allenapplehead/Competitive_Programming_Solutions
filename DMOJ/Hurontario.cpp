#include <bits/stdc++.h>
using namespace std;

// notes
// get in the habit of storing the lengths of strings in integer variables BEFOREHAND or else they will mess things up
// fastpow is always handy to have
// hashing op

typedef long long ll;
const ll PRIME =    500000000;
const ll MOD =      999999733;

string a, b;
int alen, blen;

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

ll rh (ll idx, ll prev, bool which) {
    if (which) {
        // first string
        prev *= (PRIME % MOD);
        prev += (a[alen - 1 - idx] - 'A');
        return prev % MOD;
    } else {
        // second string
        prev += (b[idx] - 'A') * fastpow(PRIME, idx) % MOD;
        return prev % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b;
    alen = a.length(); blen = b.length();
    int pointer = 0;
    int ans = 0;
    ll ahash = 0, bhash = 0;
    while (pointer < blen && alen - pointer - 1 >= 0) {
        ahash = rh(pointer, ahash, true);
        bhash = rh(pointer, bhash, false);
        if (ahash == bhash) {
            ans = max(ans, pointer + 1);
        }
        pointer++;
    }
    cout << a << b.substr(ans) << '\n';
    return 0;
}