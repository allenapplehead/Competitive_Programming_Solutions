#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int grid[51][51];
int x, y, N, startx, starty, ans, counter = 0;
int bfs (int s_y, int s_x) {
    queue<iii> queue;
    vector<ii> visited;
    iii vertex;
    iii step;
    queue.push(make_pair(make_pair(s_x, s_y), 0));
    while (queue.size() && counter <= 60) {
        vertex = queue.front();
        //cout << vertex.first.first << " " << vertex.first.second << " " << vertex.second << endl;
        queue.pop();
        if (find(visited.begin(), visited.end(), make_pair(vertex.first.first, vertex.first.second)) == visited.end()) {
            visited.push_back(make_pair(vertex.first.first, vertex.first.second));
            if (vertex.first.first < y - 1) {
                step = make_pair(make_pair(vertex.first.first + 1, vertex.first.second), vertex.second + 1); // to down
                if (grid[step.first.first][step.first.second] == 'O') {
                    queue.push(step);
                    //cout << "D: " << step.first.first << " " << step.first.second << " " << step.second << endl;
                } else if (grid[step.first.first][step.first.second] == 'W') {
                    return step.second;
                }
            } 
            if (vertex.first.first > 0) {
                step = make_pair(make_pair(vertex.first.first - 1, vertex.first.second), vertex.second + 1); // to up
                if (grid[step.first.first][step.first.second] == 'O') {
                    queue.push(step);
                    //cout << "U: " << step.first.first << " " << step.first.second << " " << step.second << endl;
                } else if (grid[step.first.first][step.first.second] == 'W') {
                    return step.second;
                } 
            } 
            if (vertex.first.second < x - 1) {
                step = make_pair(make_pair(vertex.first.first, vertex.first.second + 1), vertex.second + 1); // to right
                if (grid[step.first.first][step.first.second] == 'O') {
                    queue.push(step);
                    //cout << "R: " << step.first.first << " " << step.first.second << " " << step.second << endl;
                } else if (grid[step.first.first][step.first.second] == 'W') {
                    return step.second;
                } 
            } 
            if (vertex.first.second > 0) {
                step = make_pair(make_pair(vertex.first.first, vertex.first.second - 1), vertex.second + 1); // to left
                if (grid[step.first.first][step.first.second] == 'O') {
                    queue.push(step);
                    //cout << "L: " << step.first.first << " " << step.first.second << " " << step.second << endl;
                } else if (grid[step.first.first][step.first.second] == 'W') {
                    return step.second;
                } 
            }
        }
        counter++;
    }
    return 100000;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    while(N--) {
        cin >> x >> y;
        char ltr;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cin >> ltr;
                if (ltr == 'C') {
                    startx = i;
                    starty = j;
                }
                grid[i][j] = ltr;
            }
        }
        counter = 0;
        ans = bfs(starty, startx);
        if (ans >= 60) {
            cout << "#notworth" << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}