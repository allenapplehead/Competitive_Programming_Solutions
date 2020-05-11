#include <bits/stdc++.h>
using namespace std;

// easy problem
// make a checkerboard 
// and add another black square if needed

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        char grid[r][c];
        int lr = -1e9, lc = -1e9;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((j + i) % 2 == 0) {
                    grid[i][j] = 'B';
                } else {
                    grid[i][j] = 'W';
                    lr = i;
                    lc = j;
                }
            }
        }
        if ((r * c) % 2 == 0) {
            grid[lr][lc] = 'B';
        }
        // print
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}