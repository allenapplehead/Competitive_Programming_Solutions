#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string cur;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (cur[i] == '+') {
                cnt++;
            }
        }
        if (cnt == 2) ans++;
        else ans--;
    }
    cout << ans << '\n';
    return 0;
}