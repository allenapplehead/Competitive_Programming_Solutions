#include <bits/stdc++.h>
using namespace std;

// used editorial 

// if you look at the first part they use a smart way to colcaulte powers (they precalculate it kinda dp ish so you don't do big powers manually)
// onto the problem itself, they basically looped thru all blocks from big to small, looking at blocks on the edges and blocks in the middle
// it just becomes a math problem afterwards, it is a good way of thinking about it

const int MOD = 998244353;
vector<long long> p(200005);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    p[0] = 1;
    for (int i = 1; i < 200005; ++i) {
        p[i] = (p[i - 1] * 10) % MOD;    
    }

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        long long res = 2 * 10 * 9 * p[n - i - 1];
        res += (n - i - 1) * 10 * 9 * 9 * p[n - i - 2];
        cout << res % MOD << " ";
    }
    cout << 10 << '\n';
    return 0;
}