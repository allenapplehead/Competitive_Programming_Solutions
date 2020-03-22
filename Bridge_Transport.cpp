#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int w, n, wi;
    cin >> w >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    // sliding window
    int window = 0, ans = 0, run = 1;
    for (int i = 0; i < 4; ++i) {
        window += ar[i];
        if (window > w) {
            run = 0;
            break;
        }
        ++ans;
    }
    for (int i = 0; i < n - 4 && run > 0; ++i) {
        window -= ar[i];
        window += ar[i + 4];
        if (window > w) {
            break;
        }
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}