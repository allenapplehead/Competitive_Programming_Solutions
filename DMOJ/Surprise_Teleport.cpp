#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int r, c, sr, sc, er, ec, teleans = 1e9;

bool grid[1005][1005], t[1005][1005];

int bfs() {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(sr, sc), 0));
    while (!q.empty()) {
        int row = q.front().first.first; int col = q.front().first.second; int dist = q.front().second;
        q.pop();
        if (grid[row][col]) continue;
        grid[row][col] = true;
        if (t[row][col]) {
            teleans = min(teleans, dist);
        }
        if (row == er && col == ec) {
            // the end is found
            return dist;
        }
        // keep searching
        for (int i = 0; i < 4; ++i) {
            int nrow = row + dy[i];
            int ncol = col + dx[i];
            if (nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && grid[nrow][ncol] == false) {
                q.push(make_pair(make_pair(nrow, ncol), dist + 1));
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> sr >> sc >> er >> ec;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            char c;
            cin >> c;
            if (c == 'X') {
                grid[i][j] = true; // visited;
            }
        }
    }
    int teles;
    cin >> teles;
    for (int i = 0; i < teles; ++i) {
        int tr, tc;
        cin >> tr >> tc;
        t[tr][tc] = true;
    }
    cout << bfs() - teleans << '\n';

    return 0;
}