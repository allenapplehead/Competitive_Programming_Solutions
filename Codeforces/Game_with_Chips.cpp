#include <bits/stdc++.h>
using namespace std;

// note

// editorial solution
// just a note that if the problem does not ask for a "best" solution there is probably a sneaky way of doing it simply
// like an easy implementation
// going up in a spiral staircase form is interesting saves a lot of moves

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    // stuff all of the chips into one cell
    cout << (n - 1) + (m - 1) + n * (m - 1) + (n - 1) << '\n';
    for (int i = 1; i < n; ++i) {
        cout << "U";
    }
    for (int i = 1; i < m; ++i) {
        cout << "L";
    }
    // generate the spiral way of going up
    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << "D";
        if (i % 2 == 0) {
            for (int j = 1; j < m; ++j) {
                cout << "R";
            }
        } else {
            for (int j = 1; j < m; ++j) {
                cout << "L";
            }
        }
        
    }
    return 0;
}