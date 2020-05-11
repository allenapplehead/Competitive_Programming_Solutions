#include <bits/stdc++.h>
using namespace std;

// i struggled with this problem rip
// basically, the test data is weak, so an O(mn) time solution for each query will still pass under time
// so yeah i was misdirected
// overlaps can be very elegantly handled by counting the white squares and subtracting one if the overlapping square is white

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        vector<int> rows(n, 0);
        vector<int> cols(m, 0);
        char grid[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char c;
                cin >> c;
                grid[i][j] = c;
                if (c == '.') {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        // with that precalculated, answer each query in O(nm)
        int ans = n + m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans = min(ans, rows[i] + cols[j] - (grid[i][j] == '.'));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}