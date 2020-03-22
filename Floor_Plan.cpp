#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> rooms;

int flooring, r, c;
string s;

vector<string> plan;
bool visited[25][25];
int tot = 0;

int dfs (int rows, int col) {
    int floors = 0;
    if (!visited[rows][col]) {
        floors++;
        visited[rows][col] = true;
        for (int i = 0; i < 4; i++) {
            if (rows + dy[i] >= 0 && rows + dy[i] < r && col + dx[i] >= 0 && col + dx[i] < c && plan[rows + dy[i]][col + dx[i]]) {
                floors += dfs(rows + dy[i], col + dx[i]);
            }
        }
        return floors;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> flooring >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        plan.push_back(s);
        for (int j = 0; j < c; j++) {
            if (s[j] == 'I') visited[i][j] = 1;
        }
    }
    int filled = 0, ans = 1000000000, thatroom;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j]) {
                thatroom = dfs(i, j);
                tot += thatroom;
                rooms.push_back(thatroom);
            }
        }
    }
    sort(rooms.rbegin(), rooms.rend());
    //for (int i = 0; i < rooms.size(); ++i) cout << rooms[i] << " ";
    //cout << endl;

    for (int i = 0; i < rooms.size(); i++) {
        if (flooring - rooms[i] >= 0) {
            flooring -= rooms[i];
            filled++;
        } else {
            break;
        }
    }
    if (filled == 1) {
        cout << filled << " room, " << flooring << " square metre(s) left over" << '\n';
    } else {
        cout << filled << " rooms, " << flooring << " square metre(s) left over" << '\n';
    }
    
    return 0;
}