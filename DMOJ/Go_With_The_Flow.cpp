#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char grid[7][7];
vector<pair<int, int> > starting(9);
bool vis[7][7];
int sizes = 1e9;
//int counter = 1e9;
bool ans = false;

void printGrid() {
    //cout << "CTR: " << counter << '\n';
    cout << "+-------------------------------------+" << '\n';
    for (int i = 0; i < sizes; ++i) {
        for (int j = 0; j < sizes; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    cout << "+-------------------------------------+" << '\n';
}

bool checkGrid() {
    for (int i = 0; i < sizes; ++i) {
        for (int j = 0; j < sizes; ++j) {
            if (grid[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

void dfs(int r, int c, char marker) {
    if (ans) return;
    //cout << r << " " << c << " " << marker << '\n';
    // colour the square
    if (grid[r][c] == marker && vis[r][c] == false) {
        //vis[r][c] = true;
        // if it is already marked, then we have reached our destination
        //cout << "FOUND" << '\n';
        //printGrid();
        //cout << starting[(int)(marker - '1') + 1].first << " " << starting[(int)(marker - '1') + 1].second << '\n';
        if (!(starting[(int)(marker - '1') + 1].first == 0 && starting[(int)(marker - '1') + 1].second == 0)) {
            // start the search with a new number
            vis[starting[(int)(marker - '1') + 1].first][starting[(int)(marker - '1') + 1].second] = true;
            dfs(starting[(int)(marker - '1') + 1].first, starting[(int)(marker - '1') + 1].second, (char) (marker + 1));
        } else if (checkGrid()) {
            // base case is reached
            //cout << "PRINTING THE GRID: " << '\n';
            for (int i = 0; i < sizes; ++i) {
                for (int j = 0; j < sizes; ++j) {
                    cout << grid[i][j];
                }
                cout << '\n';
            }
            cout << '\n';
            ans = true;
            return;
        }
    } else {
        char prev = grid[r][c];
        if (grid[r][c] == '.') {
            grid[r][c] = marker;
        }
        vis[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dy[i];
            int nc = c + dx[i];
            if (nr < sizes && nr >= 0 && nc < sizes && nc >= 0) {
                if (grid[nr][nc] == '.' || (grid[nr][nc] == marker && vis[nr][nc] == false)) {
                    // valid 
                    dfs(nr, nc, marker);
                }
            }
        }
        // undo the changes
        vis[r][c] = false;
        grid[r][c] = prev;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("out.txt", "w", stdout);
    const int ROUNDS = 10;
    for (int I = 0; I < ROUNDS; ++I) {
        // resets
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < 9; ++i) starting[i] = make_pair(0, 0);
        for (int i = 0; i < 7; ++i) {
            for (int j = 0; j < 7; ++j) {
                grid[i][j] = '.';
            }
        }
        string s;
        cin >> s;
        sizes = s.length();
        for (int j = 0; j < sizes; ++j) {
            grid[0][j] = s[j];
        }
        for (int i = 1; i < sizes; ++i) {
            for (int j = 0; j < sizes; ++j) {
                cin >> grid[i][j];
                if (grid[i][j] != '.') {
                    starting[grid[i][j] - '1'] = make_pair(i, j);
                }
            }
        }
        //printGrid();
        vis[starting[0].first][starting[0].second] = true;
        dfs(starting[0].first, starting[0].second, '1');
        ans = false;
    }
    return 0;
}