#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> ii;
typedef pair<ii, double> iii;

vector<vector<int>> AdjList(3001);
vector<iii> nodes;
bitset<3001> visited;

long long path1 = 1e9, path2 = 1e9;

long long bfs(int start, int end) {
    visited.set();
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while(!q.empty()) {
        pair<int, int> vertex = q.front(); q.pop();
        if (vertex.first == end) {
            return vertex.second;
        }
        if (!visited[vertex.first]) {
            continue;
        }
        visited[vertex.first] = false;
        for (int i = 0; i < AdjList[vertex.first].size(); i++) {
            q.push(make_pair(AdjList[vertex.first][i], vertex.second + 1));
        }
    }
    return 1e9;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, max1 = -1, max2 = -1, root1, root2, end1, end2;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long double u, v, d;
        cin >> u >> v >> d;
        if (v > max1) {
            max1 = v;
            root1 = i;
        }
        if (d == 9001) {
            end1 = i;
        }
        nodes.push_back(make_pair(make_pair(u, v), d));
    }
    // create the edges for the bfs
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = 0; j < nodes.size(); j++) {
            if (i == j) continue;
            //cout << "sqrt: " << sqrt(pow((nodes1[i].first.first - nodes1[j].first.first), 2) + pow((nodes1[i].first.second - nodes1[j].first.second), 2)) << '\n';
            if (sqrt(pow((nodes[i].first.first - nodes[j].first.first), 2) + pow((nodes[i].first.second - nodes[j].first.second), 2)) <= nodes[i].second) {
                AdjList[i].push_back(j);
            }
        }
    }
    nodes.clear();
    path1 = bfs(root1, end1);

    for (int i = 0; i < 3001; i++) {
        AdjList[i].clear();
    }

    for (int i = 0; i < m; i++) {
        long double u, v, d;
        cin >> u >> v >> d;
        if (v > max2) {
            max2 = v;
            root2 = i;
        }
        if (d == 9001) {
            end2 = i;
        }
        nodes.push_back(make_pair(make_pair(u, v), d));
    }
    
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = 0; j < nodes.size(); j++) {
            if (i == j) continue;
            if (sqrt(pow((nodes[i].first.first - nodes[j].first.first), 2) + pow((nodes[i].first.second - nodes[j].first.second), 2)) <= nodes[i].second) {
                AdjList[i].push_back(j);
            }
        }
    }
    nodes.clear();
    path2 = bfs(root2, end2);
    if (path1 < path2) {
        cout << "We are the champions!" << '\n';
    } else if (path1 == path2) {
        cout << "SUDDEN DEATH" << '\n';
    } else {
        cout << ":'(" << '\n';
    }
    return 0;
}