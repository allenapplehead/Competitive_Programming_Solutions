#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// cool problem!
// remember that there is a magical formula in the editorial
// [n / i] - [n / (i + 1)] is the number of times subtrees of size i show up in n
// and you can do that for the lower square root
// for the other part, just iterate then
// note that you can not have a dp that is 1e9 big so just set it to 1e7 (the limit) and force the code to solve 1e9 queries

ll dp[10000000];

ll solve(int num) {
    ll ret = 0;
    // base case
    if (num == 1) return 1;
    for (int i = 1; i <= sqrt(num); ++i) {
        ll inc = floor(num / i) - floor(num / (i + 1));
        if (dp[i] == 0) {
            dp[i] = solve(i);
        }
        ret += dp[i] * inc;
    }
    for (int i = 2; floor(num / i) > sqrt(num); ++i) {
        if ((int)floor(num / i) > 10000000) {
            ret += solve(floor(num / i));
        } else {
            if (dp[(int)floor(num / i)] == 0) {
                dp[(int)floor(num / i)] = solve(floor(num / i));
            }
            ret += dp[(int)floor(num / i)];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}