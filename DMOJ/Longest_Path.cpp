#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(100001);
int dp[100001];
int ans = 0;
int best = 0;

int f (int vertex) {
    // base case
    if (dp[vertex]) {
        return dp[vertex]; // we already calculated the maxPath
    }
    if (!adj[vertex].size()) {
        return 0; // end of the path
    }
    int maxPath = 0, cur;
    for (int i = 0; i < adj[vertex].size(); i++) {
        cur = f(adj[vertex][i]);
        if (cur > maxPath) {
            maxPath = cur; // find the maximum downward path
        }
    }
    dp[vertex] = maxPath + 1;
    return maxPath + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < n; i++) {
        // run through every node (still O(n))
        ans = f(i);
        if (ans > best) best = ans;
    }

    cout << best << "\n";
    return 0;
}