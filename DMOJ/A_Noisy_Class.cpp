#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList (10001);
bitset<100001> black_set;
set<int> grey_set;
bool cycle = false;

void dfs(int vertex) {
    if (grey_set.find(vertex) != grey_set.end()) {
        cycle = true;
    }
    grey_set.insert(vertex);
    if (black_set[vertex] == false) {
        black_set[vertex] = true;
        for (int i = 0; i < AdjList[vertex].size(); i++) {
            dfs(AdjList[vertex][i]);
        }
    }
    grey_set.erase(vertex);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // just cycle check
    int n, m;
    cin >> n >> m;
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v);
    }
    for (int i = 1; i < n; i++) {
        if (!black_set[i])
            dfs(i);
    }
    if (cycle) {
        cout << "N" << '\n';
    } else {
        cout << "Y" << '\n';
    }
    return 0;
}