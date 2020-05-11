#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int t, n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        int cur = grid[0][0];
        // bfs
        int ans = 0;
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push(make_pair(make_pair(0, 0), make_pair(0, cur)));
        bool found = false;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int oxygen = q.front().second.first;
            int h = q.front().second.second;
            q.pop();
            if (r == n - 1 && c == n - 1) {
                cout << oxygen << '\n';
                cout << '\n';
                found = true;
                break;
            }
            if (grid[r][c] == -1) {
                continue;
            } else {
                for (int i = 0; i < 4; ++i) {
                    if (r + dy[i] >= 0 && r + dy[i] < n && c + dx[i] >= 0 && c + dx[i] < n && std::abs(grid[r][c] - grid[r + dy[i]][c + dx[i]]) <= 2 && grid[r + dy[i]][c + dx[i]] != -1) {
                        q.push(make_pair(make_pair(r + dy[i], c + dx[i]), make_pair(oxygen + ((grid[r][c] > cur || grid[r + dy[i]][c + dx[i]] > cur) ? 1 : 0), grid[r + dy[i]][c + dx[i]])));
                    }
                }
            }
            grid[r][c] = -1; // mark as visited
        }
        if (!found) {
            cout << "CANNOT MAKE THE TRIP" << '\n';
            cout << '\n';
        }
    }
    return 0;
}