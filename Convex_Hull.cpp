#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

vector<vector<iii> > AdjList(2005);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int k, m, n;
  cin >> k >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, t, h;
    cin >> a >> b >> t >> h;
    AdjList[a].push_back(make_pair(t, make_pair(b, h)));
    AdjList[b].push_back(make_pair(t, make_pair(a, h)));
  }
  int source, dest;
  cin >> source >> dest;
  // dijkstra
  int dist[2005][205];
  for (int i = 0; i < 2005; ++i) {
    for (int j = 0; j < 205; ++j) {
      dist[i][j] = 1e9;
    }
  }
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, source));

  bool inq[2005];
  memset(inq, false, sizeof(inq));
  dist[source][0] = 0;
  inq[source] = true;

  while (!pq.empty()) {
    int curDist = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    inq[node] = false;
    for (int i = 0; i < AdjList[node].size(); ++i) {
      for (int j = 0; j < k - AdjList[node][i].second.second; ++j) {
        if (dist[AdjList[node][i].second.first][j + AdjList[node][i].second.second] > dist[node][j] + AdjList[node][i].first) {
          dist[AdjList[node][i].second.first][j + AdjList[node][i].second.second] = dist[node][j] + AdjList[node][i].first;
          if (!inq[AdjList[node][i].second.first]) {
            inq[AdjList[node][i].second.first] = true;
            pq.push(ii(dist[node][j] + AdjList[node][i].first, AdjList[node][i].second.first));
          }
        }
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i < k; ++i) {
    ans = min(ans, dist[dest][i]);
  }
  if (ans == 1e9) ans = -1;
  cout << ans << '\n';
  return 0;
}