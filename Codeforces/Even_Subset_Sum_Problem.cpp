#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);

        int evenidx = -1e9;
        int oddidx1 = -1e9;
        int oddidx2 = -1e9;

        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            if (ar[i] % 2 == 0) {
                evenidx = i;
            } else if (oddidx1 == -1e9) {
                oddidx1 = i;
            } else if (oddidx2 == -1e9) {
                oddidx2 = i;
            }
        }

        if (evenidx >= 0) {
            cout << 1 << '\n';
            cout << evenidx + 1 << '\n';
        } else if (oddidx1 != -1e9 && oddidx2 != -1e9) {
            cout << 2 << '\n';
            cout << oddidx1 + 1 << " " << oddidx2 + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}