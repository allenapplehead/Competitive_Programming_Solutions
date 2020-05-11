#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

long long dp[2005];
long long backup[2005];
bitset<2005> marked;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, T, Q, t, qi, a, b;
    cin >> N >> T >> Q;
    vector<ll> arr(N);
    long long mini = 1e9, mini2 = 1e9;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] < mini) {
            mini2 = mini;
            mini = arr[i];
        } else if (arr[i] < mini2) {
            mini2 = arr[i];
        }
    }
    // use knapsack as a generator function
    for (int i = T; i >= mini + mini2; i--) {
        dp[i] = 1;
    }
    for (int i = 0; i <= N; i++) {
        for (int j = T; j >= arr[i]; j--) {
            dp[j] = dp[j] % MOD + dp[j - arr[i]] % MOD;
            backup[j] = dp[j];
        }
    }

    cout << "printing dp: " << '\n';
    for (int i = 0; i <= 12; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    while (Q--) {
        cin >> a >> b >> qi;
        a--;
        b--;
        // remove the items from the knapsack
        /* for (int i = arr[a]; i <= qi; i++) {
            dp[i] -= dp[i - arr[a]] % MOD;
        }
        for (int i = arr[b]; i <= qi; i++) {
            dp[i] -= dp[i - arr[b]] % MOD;
        } */
        cout << dp[qi - arr[a] - arr[b]] % MOD << '\n';
        for (int i = 0; i < N; i++) dp[i] = backup[i];
    }
    return 0;
}