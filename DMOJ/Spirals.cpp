#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("outt.txt", "w", stdout);
    int grid[101][101];
    int q;
    cin >> q;
    while (q--) {
        memset(grid, 0, sizeof(grid));
        int start, end;
        cin >> start >> end;
        int lx = 50, ly = 50;
        grid[ly][lx] = start;
        int d = 0, sx = 0, sy = 1, six = 1, siy = 1;
        for (int i = start + 1; i <= end; ++i) {
            if (grid[ly + dy[d % 4]][lx + dx[d % 4]] == 0) {
                grid[ly + dy[d % 4]][lx + dx[d % 4]] = i;
                ly = ly + dy[d % 4];
                lx = lx + dx[d % 4];
                six = max(six, sx + 1);
                sx = 1;
                siy = max(siy, sy + 1);
                sy = 1;
                d++;
            } else {
                grid[ly + dy[(d + 3) % 4]][lx + dx[(d + 3) % 4]] = i;
                ly = ly + dy[(d + 3) % 4];
                lx = lx + dx[(d + 3) % 4];
                if (dx[(d + 3) % 4] == 0) {
                    sy++;
                } else {
                    sx++;
                }
            }
        }
        int leftstart = (six - 1) / 2;
        int topstart = (siy - 1) / 2;
        for (int i = 50 - topstart; i < 50 + siy - topstart; i++) {
            for (int j = 50 - leftstart; j < 50 + leftstart * 2 + 1; j++) {
                if (grid[i][j] == 0) {
                    cout << "  ";
                    if (j < 50 + leftstart * 2) cout << ' ';
                } else {
                    if (grid[i][j] < 10) cout << ' ';
                    cout << grid[i][j];
                    if (j < 50 + leftstart * 2) cout << ' ';
                }
            }
            cout << '\n';
        }
        if (q > 0) cout << "\n";
    }
    
    return 0;
}