#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList (26);
vector<pair<pair<int, int>, string>> lib;

bool bfs(int is, int ie) {
    bool visited[26];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    vector<int> illegal;
    illegal.push_back(is);
    illegal.push_back(ie);
    sort(illegal.begin(), illegal.end());
    q.push(0);
    while (!q.empty()) {
        int vertex = q.front(); q.pop();
        if (vertex == 1) {
            return true;
        }
        if (visited[vertex] == false) {
            visited[vertex] = true;
            for (int i = 0; i < AdjList[vertex].size(); i++) {
                int sml = min(AdjList[vertex][i], vertex);
                int big = max(AdjList[vertex][i], vertex);
                if (sml == illegal[0] && big == illegal[1]) {
                    continue;
                }
                q.push(AdjList[vertex][i]);
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string path;
    cin >> path;
    while (path != "**") {
        AdjList[path[0]-65].push_back(path[1]-65);
        AdjList[path[1]-65].push_back(path[0]-65);
        lib.push_back(make_pair(make_pair(path[0]-65, path[1]-65), path));
        cin >> path;
    }
    // take away edges one by one and check with breadth first search
    int counter = 0;
    for (auto i : lib) {
        if (!bfs(i.first.first, i.first.second)) {
            counter++;
            cout << i.second << '\n';
        }
    }
    cout << "There are " << counter << " disconnecting roads." << '\n';
    return 0;
}