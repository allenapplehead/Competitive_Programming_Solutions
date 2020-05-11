#include <bits/stdc++.h>
using namespace std;

// the editorial has a really good diagram using whats called a "polyline"
// basically, what goes down, comes back up. All the parts that are under 0 (all the line segments) will need to be operated on at least once
// so just sum those together

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    // process into a prefix sum array
    int ps[s.length() + 1];
    ps[0] = 0;
    for (int i = 1; i <= s.length(); ++i) {
        ps[i] = ps[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
    if (ps[s.length()] != 0) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (ps[i] + ps[i + 1] < 0) {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}