#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ln '\n'
bool visited[51][51];
int dist[51][51];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
void bfs() {
    int l, w;
    ii start;
    cin >> l >> w;
    vector<string> grid;
    string s;
    cin.ignore();
    for (int i = 0; i < w; i++) {
        getline(cin, s);
        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == 'C') {
                start.X = i; // X
                start.Y = j; // Y
            }
        }
        grid.pb(s);
    }
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    visited[start.X][start.Y] = 1;
    queue<ii> q;
    q.push(start);
    dist[start.X][start.Y] = 0;
    while(!q.empty()) {
        ii vertex = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ii adj = {dx[i] + vertex.X, dy[i] + vertex.Y};
            if (adj.X >= 0 && adj.X < w && adj.Y >= 0 && adj.Y < l && !visited[adj.X][adj.Y] and grid[adj.X][adj.Y] != 'X') {
                visited[adj.X][adj.Y] = 1;
                dist[adj.X][adj.Y] = dist[vertex.X][vertex.Y] + 1;
                if (grid[adj.X][adj.Y] == 'W') {
                    if (dist[adj.X][adj.Y] >= 60) {
                        cout << "#notworth" << ln;
                    } else {
                        cout << dist[adj.X][adj.Y] << ln;
                    }
                    return;
                }
                q.push(adj);
            }
        }
    }
    cout << "#notworth" << ln;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    while (N--) {
        bfs();
    }
    return 0;
}