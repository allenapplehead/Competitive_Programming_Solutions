#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList(200005);
vector<vector<int>> ta(2, vector<int>(200005));
bitset<200005> visited;

void dfs(int vertex, int dist, int selection) {
    if (visited[vertex] == false) {
        ta[selection][vertex] = dist;
        visited[vertex] = true;
        for (int i = 0; i < AdjList[vertex].size(); ++i) {
            dfs(AdjList[vertex][i], dist + 1, selection);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, u, v = 0;
    cin >> n >> u;
    u--;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        AdjList[a - 1].push_back(b - 1);
        AdjList[b - 1].push_back(a - 1);
    }
    dfs(u, 0, 0);
    visited.reset();
    dfs(v, 0, 1);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ta[1][i] > ta[0][i]) {
            ans = max(ans, ta[0][i] + (ta[1][i] - ta[0][i]));
        }
    }
    cout << ans * 2 << '\n';

    return 0;
}