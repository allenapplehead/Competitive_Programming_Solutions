#include <bits/stdc++.h>
using namespace std;

// basically what i did is manually generate all the permutations and find a greedy strategy to do that faster
// i realized its kinda like moving the first letter to the back during each permutation
// but there was a caveat depending on the parity of n and which row it was on but i figured it out after some debugging

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // string backup = s;
        // for (int i = 2; i <= n; ++i) {
        //     for (int j = i - 1; j < n; ++j) {
        //         reverse(s.begin() + j - i + 1, s.begin() + j - i + 1 + i);
        //     }
        //     cout << s << '\n';
        //     s = backup;
        // }
        // cout << "+------------------------------------+" << '\n';
        vector<pair<string, int> > order;
        for (int i = 1; i < n; ++i) {
            string temp = s.substr(i - 1);
            if ((i + n) % 2 == 0) {
                for (int j = i - 2; j >= 0; --j) {
                    temp += s[j];
                }
            } else {
                temp += s.substr(0, i - 1);
            }   
            // cout << temp << '\n';
            order.push_back(make_pair(temp, i));
        }
        reverse(s.begin(), s.end());
        order.push_back(make_pair(s, n));
        sort(order.begin(), order.end());
        cout << order[0].first << '\n' << order[0].second << '\n';
    }
    return 0;
}