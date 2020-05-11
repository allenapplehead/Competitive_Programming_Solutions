#include <bits/stdc++.h>
using namespace std;

int N, k, b[201];
vector<int> c(201);
vector<int> dp(20001, 1e9);

long long counter = 0;

void f(int cur, vector<int> p) {
    for (int i = 0; i < N; i++) {
        if (p[i] > 0 && cur + b[i] <= k) {
            dp[cur + b[i]] = min(dp[cur + b[i]], dp[cur] + 1);
            p[i]--;
            f(cur + b[i], p);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> b[i];
    for (int i = 0; i < N; i++) cin >> c[i];
    cin >> k;
    dp[0] = 0;
    f(0, c);
    cout << dp[k] << "\n";
    return 0;
}