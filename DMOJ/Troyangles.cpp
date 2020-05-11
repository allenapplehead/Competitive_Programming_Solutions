#include <bits/stdc++.h>
using namespace std;

int N, grid[2005][2005];
char c;
long long res = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        grid[i][0] = 0;
        grid[i][N + 1] = 0;
        for (int j = 1; j < N + 1; j++) {
            cin >> c;
            if (c == '.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 1; j < N + 1; j++) {
            if (grid[i][j])
                grid[i][j] += min(min(grid[i + 1][j - 1], grid[i + 1][j]), grid[i + 1][j + 1]);
        }
    }
    // sum them all up
    /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 2; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << "\n";
    } */
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N + 1; j++) {
            res += grid[i][j];
        }
    }
    cout << res << "\n";
    return 0;
}