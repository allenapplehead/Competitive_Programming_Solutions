#include <bits/stdc++.h>
using namespace std;

char grid[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int r, int c, int er, int ec) {
    bool visited[25][25];
    memset(visited, false, sizeof(visited));
    // set illegal boudnaries
    for (int i = 0; i < 25; ++i) {
        visited[0][i] = true;
        visited[i][0] = true;
    }
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(r, c), 0));
    while (!q.empty()) {
        pair<pair<int, int>, int> vertex = {{q.front().first.first, q.front().first.second}, q.front().second}; q.pop();
        if (visited[vertex.first.first][vertex.first.second] == false) {
            //cout << "visiting: " << vertex.first.first << " " << vertex.first.second << '\n';
            //cout << "grid is: " << grid[vertex.first.first][vertex.first.second] << endl;
            visited[vertex.first.first][vertex.first.second] = true;
            // check if we reached the target
            if (vertex.first.first == er && vertex.first.second == ec && grid[vertex.first.first][vertex.first.second] != '*') {
                return vertex.second + 1;
            }
            if (grid[vertex.first.first][vertex.first.second] == '+') {
                for (int i = 0; i < 4; ++i) {
                    q.push(make_pair(make_pair(vertex.first.first + dy[i], vertex.first.second + dx[i]), vertex.second + 1));
                }
            } else if (grid[vertex.first.first][vertex.first.second] == '-') {
                for (int i = 0; i < 2; ++i) {
                    q.push(make_pair(make_pair(vertex.first.first + dy[i], vertex.first.second + dx[i]), vertex.second + 1));
                }
            } else if (grid[vertex.first.first][vertex.first.second] == '|') {
                for (int i = 2; i < 4; ++i) {
                    q.push(make_pair(make_pair(vertex.first.first + dy[i], vertex.first.second + dx[i]), vertex.second + 1));
                    //cout << "pushed: " << r + dy[i] << c + dx[i] << endl;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> grid[i + 1][j + 1];
            }
        }
        cout << bfs(1, 1, r, c) << '\n';
    }
    return 0;
}