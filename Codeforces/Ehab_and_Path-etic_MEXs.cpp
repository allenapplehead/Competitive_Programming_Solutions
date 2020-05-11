#include <bits/stdc++.h>
using namespace std;

// used editorial solution

// basically, notice that the node with the largest indegree will be in a sense the "central node"
// so just make the edges around that node the smallest and you are good
// no need for dp on trees or whatev

vector<vector<int> > adj(200010);
int ans[200010];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        ans[i] = -1;
    }
    pair<int, int> mx = make_pair(0, 0);
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, make_pair((int)adj[i].size(), i));
    }
    // now distribute the minimum numbers around the node with the biggest indegree
    int cur = 0;
    for (int i = 0; i < adj[mx.second].size(); ++i) {
        ans[adj[mx.second][i]] = cur;
        cur++;
    }
    // now distribute the rest of the numbers arbitrarily
    for (int i = 0; i < n - 1; ++i) {
        if (ans[i] == -1) {
            ans[i] = cur;
            cur++;
        }
        cout << ans[i] << '\n';

    }
    return 0;
}