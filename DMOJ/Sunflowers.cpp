#include <bits/stdc++.h>
using namespace std;

long long grid[101][101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<long long> r;
    vector<long long> rs;
    vector<long long> c;
    vector<long long> cs;
    for (int i = 0; i < n; ++i) {
        r.push_back(grid[0][i]);
        rs.push_back(grid[0][i]);
        c.push_back(grid[i][0]);
        cs.push_back(grid[i][0]);
    }
    sort(rs.begin(), rs.end());
    sort(cs.begin(), cs.end());
    bool hsorted = true, vsorted = true;
    for (int i = 0; i < n; ++i) {
        if (r[i] != rs[i]) {
            hsorted = false;
        }
        if (c[i] != cs[i]) {
            vsorted = false;
        }
    }
    // its just casework now
    if (hsorted && vsorted) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j];
                if (j == n - 1) {
                    cout << '\n';
                } else {
                    cout << " ";
                }
            }
        }
    }
    if (!hsorted && vsorted) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[j][i];
                if (j == n - 1) {
                    cout << '\n';
                } else {
                    cout << " ";
                }
            }
        }
    }
    if (!hsorted && !vsorted) {
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                cout << grid[i][j];
                if (j == 0) cout << '\n';
                else cout << " ";
            }
        }
    }
    if (hsorted && !vsorted) {
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                cout << grid[j][i];
                if (j == 0) cout << '\n';
                else cout << " ";
            }
        }
    }


    return 0;
}