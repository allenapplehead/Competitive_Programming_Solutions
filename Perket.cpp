#include <bits/stdc++.h>
using namespace std;

long long ans = 9223372036854775807;

void solve(vector<pair<long long, long long>> ingred, long long start, long long s, long long b) {
    // base case
    if (start == ingred.size()) {
        return;
    }
    for (int i = start; i < ingred.size(); ++i) {
        s *= ingred[i].first;
        b += ingred[i].second;
        solve(ingred, i + 1, s, b);
        // process the subset now

        ans = min(ans, abs(s - b));
        s /= ingred[i].first;
        b -= ingred[i].second;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long s, b;
    vector<pair<long long, long long>> ingred(n);
    for (int i = 0; i < n; ++i) {
        cin >> s >> b;
        ingred[i] = make_pair(s, b);
    }
    // brute force all the subsets recusively
    solve(ingred, 0, 1, 0);
    cout << ans << '\n';
    return 0;
}