#include <bits/stdc++.h>
using namespace std;

int baseCry [5][5] = {{0, 1, 1, 1, 0}, {0, 2, 1, 2, 0}, {0, 0, 2, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

int solve(int level, long long r, long long c) {
    if (level <= 0) {
        return 0;
    } 
    int n_r, n_c;
    n_r = r / pow(5, level - 1);
    n_c = c / pow(5, level - 1);
    if (baseCry[n_r][n_c] != 2) return baseCry[n_r][n_c];
    return solve(level - 1, r % (long long) pow(5, level - 1), c % (long long) pow(5, level - 1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, m, x, y;
    cin >> t;
    while (t--) {
        cin >> m >> x >> y;
        int resp = solve(m, y, x);
        if (resp == 1) cout << "crystal" << '\n';
        else if (resp == 0) cout << "empty" << '\n';
        else cout << resp << '\n';
    }

    return 0;
}