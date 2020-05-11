#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> AdjList (1005);

int dfs(ll start, ll end) {
    stack<pair<ll, ll>> s;
    bitset<1005> nvisited;
    nvisited.set();
    s.push(make_pair(start, 0));
    ll vertex, dist;
    while(!s.empty()) {
        vertex = s.top().first; 
        dist = s.top().second;
        s.pop();
        if (vertex == end) {
            return dist;
        }
        if (nvisited[vertex]) {
            nvisited[vertex] = 0;
            for (int i = 0; i < AdjList[vertex].size(); i++) {
                s.push(make_pair(AdjList[vertex][i], dist + 1));
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, t;
    cin >> n >> m >> t;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        AdjList[u - 1].push_back(v - 1);
    }
    ll q;
    cin >> q;
    while(q--) {
        ll u, v;
        cin >> u >> v;
        ll path = dfs(u - 1, v - 1) * t;
        if (path == -1 * t) {
            cout << "Not enough hallways!" << '\n';
        } else {
            cout << path << '\n';
        }
    }
    return 0;
}