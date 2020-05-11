#include <bits/stdc++.h>
using namespace std;

// basically just an implementation problem so be thorough
// there are three conditions that I made that would make the answer NO
// if s already contains characters that are not in t (or too many) then we know it is impossible
// if the letters in s are in the wrong order
// if there are not enough characters for s to have to be t

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s, t, p;
        cin >> s >> t >> p;
        int tgt[26];
        memset(tgt, 0, sizeof(tgt));
        int cur[26];
        memset(cur, 0, sizeof(cur));

        for (int i = 0; i < t.length(); ++i) {
            tgt[t[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); ++i) {
            cur[s[i] - 'a']++;
        }

        // validity
        string ans = "YES";

        for (int i = 0; i < 26; ++i) {
            if (cur[i] > tgt[i]) {
                ans = "NO";
                break;
            }
        }

        int ctr = 0;
        for (int i = 0; i < t.length(); ++i) {
            if (s[ctr] == t[i]) {
                ctr++;
            }
        }
        if (ctr < s.length()) {
            ans = "NO";
        }

        for (int i = 0; i < p.length(); ++i) {
            cur[p[i] - 'a']++;
        }

        // now check if it is valid
        for (int i = 0; i < 26; ++i) {
            if (tgt[i] > cur[i]) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}