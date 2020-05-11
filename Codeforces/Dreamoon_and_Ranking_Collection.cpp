#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int g;
        bool visited[205];
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; ++i) {
            cin >> g;
            visited[g] = true;
        }

        int ans = 0;
        while (true) {
            if (visited[ans + 1]) {
                ans++;
            } else {
                if (x - 1 < 0) {
                    break;
                } else {
                    x--;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}