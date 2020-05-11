#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    int lowidx = 1e9, highidx = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        if (ar[i] == 1) lowidx = i;
        else if (ar[i] == n) highidx = i;
    }
    cout << max(highidx, lowidx) - min(highidx, lowidx) + max(n - 1 - max(highidx, lowidx), min(highidx, lowidx)) << '\n';
    return 0;
}