#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList(10000);
int dp[10000];

int dfs(int start, int end) {
    int p = 0;
    if (dp[start]) return dp[start];
    if (start == end) {
        dp[start] = 1;
        return 1;
    }
    if (!AdjList[start].size()) {
        return 0;
    }
    for (int i = 0; i < (int)AdjList[start].size(); ++i) {
        p += dfs(AdjList[start][i], end);
    }
    dp[start] = p;
    return p;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int u, v;
    cin >> u >> v;
    while (u && v) {
        AdjList[u].push_back(v);
        cin >> u >> v;
    }
    dfs(1, n);
    cout << dp[1] << '\n';

    return 0;
}