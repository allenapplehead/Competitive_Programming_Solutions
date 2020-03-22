#include <bits/stdc++.h>
using namespace std;

int vis[150005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        vis[ar[i]]++;
    }
    sort(ar.begin(), ar.end());
    // try lowering

    for (int i = 0; i < n; ++i) {
        if (ar[i] - 1 != 0 && vis[ar[i] - 1] == 0) {
            vis[ar[i]]--;
            ar[i]--;
            vis[ar[i]]++;
        }
    }

    // try raising
    sort(ar.rbegin(), ar.rend());
    for (int i = 0; i < n; ++i) {
        if (vis[ar[i] + 1] == 0) {
            vis[ar[i]]--;
            ar[i]++;
            vis[ar[i]]++;
        }
    }

    // count the number of unique numbers
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (ar[i] != ar[i - 1]) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}