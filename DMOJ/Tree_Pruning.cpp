#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, w, x, y;
vector<ll> weights(1000005);
vector<vector<ll>> AdjList(1000005);
bitset<1000005> bs;

vector<ll> ans;
stack<int> s;

bool solve(int vertex, ll dist) {
    if (!bs[vertex]) return false;
    bs[vertex] = false;
    s.push(vertex);
    if (dist >= k && dist <= 2 * k) {
        // print the answer
        int sz = s.size();
        cout << sz << '\n';
        for (int i = 0; i < sz; ++i) {
            cout << s.top();
            if (i == sz - 1) cout << '\n';
            else cout << ' ';
            s.pop();
        }
        return true;
    }
    bool found = false;
    for (int i = 0; i < AdjList[vertex].size(); ++i) {
        found = solve(AdjList[vertex][i], dist + weights[AdjList[vertex][i]]);
        if (found) return true;
    }
    s.pop();
    return false;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        bs[x] = true;
        bs[y] = true;
        AdjList[x].push_back(y);
        AdjList[y].push_back(x);
    }
    // prune out all nodes that are greater than 2K or answer is found when a node between [K, 2K] is found
    for (int i = 1; i <= n; ++i) {
        if (weights[i] > 2 * k) {
            bs[i] = false;
        } else if (weights[i] >= k && weights[i] <= 2 * k) {
            cout << 1 << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    // all the remaining nodes are under K, so just bfs/dfs (flood fill)
    for (int i = 1; i <= n; ++i) {
        if (bs[i]) {
            if (solve(i, weights[i])) {
                return 0;
            }
            while (s.size()) {
                s.pop();
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}