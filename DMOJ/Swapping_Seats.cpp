#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a = 0; // counts the number of a's
    string s;
    cin >> s;

    s = s + s;
    // this code will only deal with 4/15 marks (only ab)

    // prefix sum to count number of b's at any location
    int ps[2 * s.length() + 1];
    memset(ps, 0, sizeof(ps));

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A') {
            a++;
            ps[i + 1] = ps[i];
        } else {
            ps[i + 1] = ps[i] + 1;
        }
    }

    a /= 2;

    int ans = 1e9;

    // // debug
    // for (int i = 0; i < 2 * s.length() + 1; ++i) {
    //     cout << ps[i] << ' ';
    // }
    // cout << endl;

    // brute force the "splitting index"
    for (int i = 1; i <= s.length() / 2; ++i) {
        // find how many b's that need to be moved
        //cout << ps[i + a - 1] << " " << ps[i - 1] << '\n';
        ans = min(ans, ps[i + a - 1] - ps[i - 1]);
    }
    cout << ans << '\n';
    return 0;
}