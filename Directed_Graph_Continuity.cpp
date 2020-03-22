#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList(51);
bool visited[51];
int n, m;

bool dfs(int start, int banu, int banv) {
    // base case
    if (start == n) {
        return true;
    }
    if (!visited[start]) {
        visited[start] = true;
        for (int i = 0; i < AdjList[start].size(); ++i) {
            if (!(start == banu && AdjList[start][i] == banv)) {
                if(dfs(AdjList[start][i], banu, banv)) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<pair<int, int>> edges;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        edges.push_back(make_pair(u, v));
    }
    for (auto edge : edges) {
        memset(visited, false, sizeof(visited));
        if (dfs(1, edge.first, edge.second)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}