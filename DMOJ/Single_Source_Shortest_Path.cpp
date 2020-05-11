#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1e9
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int V, E, u, v, w;
    vector<vii> AdjList;
    cin >> V >> E;

    AdjList.assign(V + 1, vii()); // assign V blank vectors to AdjList
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    // Dijkstra routine
    vi dist(V + 1, INF); dist[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, 1));

    while (!pq.empty()) {
        ii front = pq.top(); pq.pop(); // pop front the FRONT
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // if distance to u is greater than the previous distance to u
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }

    for (int k = 1; k <= V; k++) {
        if (dist[k] == 1000000000) cout << -1 << "\n";
        else cout << dist[k] << "\n";
    }
    return 0;
}