#include <bits/stdc++.h>
using namespace std;

// yay i solved another one by myself
// basically I need to get better implementing binary search
// also computiting billions of instructions still passes really nicely on codeforces
// to solve this basically iterate through the string from beginning to end into a prefix sum array of costs
// then binary search (using lower and upper bounds) the upper bound to find the index
// I had to use lower bound as well as if the difference happens to be equal to the upper bound it will not give the correct thing

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        // create a prefix sum array
        vector<ll> ps(s.length() + 1);
        ps[0] = 0;
        char prev = 'C';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != prev && i < s.length() - 1) {
                prev = s[i];
                ps[i + 1] = ps[i] + (s[i] == 'A' ? a : b);
            } else {
                ps[i + 1] = ps[i];
            }
        }
        // // debug
        // for (int i = 0; i < s.length() + 1; ++i) {
        //     cout << ps[i] << ' ';
        // }
        // cout << endl;
        if (p >= ps[s.length()]) {
            cout << 1 << '\n';
        } else {
            // binary search
            ll dif = ps[s.length()] - p;
            
            // find the upper bound
            ll mid = lower_bound(ps.begin(), ps.end(), dif) - ps.begin();
            mid = upper_bound(ps.begin(), ps.end(), ps[mid]) - ps.begin();
            if (mid > s.length()) {
                cout << s.length() << '\n';
            } else 
            cout << mid << '\n';
        }
    }
    return 0;
}