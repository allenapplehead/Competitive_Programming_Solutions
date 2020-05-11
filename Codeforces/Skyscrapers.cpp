#include <bits/stdc++.h>
using namespace std;
 
// SQUARE ROOT DECOMP !!!!!!!!!!!!!!!!!!!!
// https://www.geeksforgeeks.org/range-minimum-query-for-static-array/

// look ad editorial for the RECURSIVE routine

typedef long long ll;
pair<ll, ll> dp[500005]; // n states, where the minimum element is
ll ar[500005];
ll ans[500005];
pair<ll, ll> decomp[710]; // square root of 500005
int bsz;
 
void preprocess(int n) {
    // initialize block pointer
    int bptr = 0;
    
    // calculate the size of each block
    bsz = sqrt(n);
 
    // build
    ll mi = 1e18;
    int midx = -1;

    for (int i = 0; i < n; ++i) {
        //mi = min(mi, ar[i]);
        if (ar[i] < mi) {
            mi = ar[i];
            midx = i;
        }
        if ((i + 1) % bsz == 0) {
            decomp[bptr].first = mi;
            decomp[bptr].second = midx;
            bptr++;
            mi = 1e18;
            midx = -1;
        }
    }
}
 
pair<ll, ll> query (int l, int r) {
    ll ret = 1e18;
    ll idx = -1;
    // [l, r]
    do {
        if (ar[l] < ret) {
            ret = ar[l];
            idx = l;
        }
        l++;
    } while (l <= r && l % bsz != 0);
    // l is currently unscanned
    while (l + bsz - 1 <= r) {
        if (decomp[(l + bsz) / bsz - 1].first < ret) {
            ret = decomp[(l + bsz) / bsz - 1].first;
            idx = decomp[(l + bsz) / bsz - 1].second;
        }
        l += bsz;
    }
    // l is again unscanned
    while (l <= r) {
        if (ar[l] < ret) {
            ret = ar[l];
            idx = l;
        }
        l++;
    }
    return make_pair(ret, idx);
}
 
ll solve(int l, int r) {
    // [l, r] inclusive
 
    // define base case
    if (l > r) {
        return 0;
    }
    if (l == r) {
        ans[l] = ar[l];
        return ar[l];
    }
 
    pair<ll, ll> res = query(l, r);
    ll mi = res.first;
    int midx = res.second;
    
    if (dp[midx].first != 0) {
        if (dp[midx].second == 1) {
            // a was greater
            for (int i = midx; i <= r; ++i) {
                ans[i] = mi;
            }
        } else {
            // b was greater
            for (int i = l; i <= midx; ++i) {
                ans[i] = mi;
            }
        }
        return dp[midx].first;
    }
 
    ll ret = 0;
    ll a = max(ret, solve(l, midx - 1) + mi * (r - midx + 1));
    ll b = max(ret, mi * (midx - l + 1) + solve(midx + 1, r));
    if (a >= b) {
        ret = a;
        for (int i = midx; i <= r; ++i) {
            ans[i] = mi;
        }
        dp[midx].first = a;
        dp[midx].second = 1;
    } else {
        ret = b;
        for (int i = l; i <= midx; ++i) {
            ans[i] = mi;
        }
        dp[midx].first = b;
        dp[midx].second = 2;
    }
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    preprocess(n);
    solve(0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}