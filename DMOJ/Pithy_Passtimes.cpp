#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.length() <= 10) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}