#include <bits/stdc++.h>
using namespace std;

// solved it myself

// basically, notice how for each subset you divide it into, each must contain one of the n - k + 1 (at least that big)
// numbers (so if k == 3, then each segment must contain one of the three biggest numbers)
// record the indices of those elements, and look thru them seeing how far you can extend its right boundary

const int MOD = 998244353;

vector<long long> biggest;
vector<long long> ar(200005);

int n, k;

long long solve(int level) {
    // base case
    if (level == k - 1) {
        return 1;
    }
    long long ret = 0;
    long long sub = solve(level + 1) % MOD;
    ret = sub * (biggest[level + 1] - biggest[level]);
    return ret % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long large = 0;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (ar[i] >= n - k + 1) {
            large += ar[i];
            biggest.push_back(i);
        }
    }

    cout << large << " " << solve(0) << '\n';
    return 0;
}