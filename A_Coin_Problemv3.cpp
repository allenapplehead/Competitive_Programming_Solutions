#include <bits/stdc++.h>
using namespace std;

int N, V, l, c, coins[2001], dp[3][10001]; // do space optimization
vector<pair<int, int>> order;
map<int, vector<int>> query;
int u = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];    // one indexed
    }
    // get input first, then calculate strategically
    int f, s;
    while (V--) {
        cin >> f >> s;
        order.push_back(make_pair(f, s));
        if (query.find(f) == query.end()) {
            query.insert(make_pair(f, s));
        } else {
            query[f].push_back(s);
        }
        for (int i = 1; i < 10001; i++) {
            dp[0][i] = 1e9;
        }
    }
    // process in ascending order
    int curval;
    for (int i = 1; i <= N; i++) {
        for (int rem = 0; rem < coins[i]; rem++) {
            deque<int> d;
            for (int j = 0; j <= (10001 - rem) / coins[i]; j++) {
                curval = coins[i] * j + rem;
                if (dp[i - 1][curval] != 1e9) {
                    while (!d.empty() && dp[i - 1][d.back() * coins[i] + rem] + j - d.back() >= dp[i - 1][curval]) {
                        d.pop_back();
                    }
                    d.push_back(j);
                }
                if (d.empty())
                    dp[i][curval] = 1e9;
                else
                    dp[i][curval] = dp[i - 1][coins[i] * d.front() + rem] + j - d.front();
            }
        }
    }
    while (V--) {
        cin >> c >> l;
        if (dp[l][c] == 1e9) dp[l][c] = -1;
        cout << dp[l][c] << "\n";
    }
    return 0;
}