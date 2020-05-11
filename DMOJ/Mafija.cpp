#include <bits/stdc++.h>
using namespace std;

int AdjList[500001];
int inDeg[500001];
bitset<500001> visited;

int mafias = 0;

void dfs(int vertex, bool maf) {
    if (visited[vertex]) return;
    visited[vertex] = true;
    mafias += maf;
    if (--inDeg[AdjList[vertex]] == 0 || maf) {
        dfs(AdjList[vertex], !maf);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int v, i = 0; i < n; i++) {
        cin >> v;
        v--;
        AdjList[i] = v;
        inDeg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (inDeg[i] == 0) {
            dfs(i, true);
        }
    }
    for (int i = 0; i < n; i++) {
        dfs(i, false);
    }
    cout << mafias << '\n';
    return 0;
}