#include <bits/stdc++.h>
using namespace std;

int events[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 10;
    while (T--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> ar(m);
        memset(events, false, sizeof(events));
        for (int i = 0; i < m; ++i) {
            cin >> ar[i];
            events[ar[i]]++;
        }
        int shirts = n;
        int ans = 0;
        int have = n;
        for (int i = 1; i <= d; ++i) {
            if (shirts == 0) {
                ans++;
                shirts = have - 1;
            } else {
                shirts--;
            }
            if (events[i] > 0) {
                shirts += events[i];
                have += events[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}