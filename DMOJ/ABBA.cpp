#include <bits/stdc++.h>
using namespace std;

// basically, scan thru the string backwards and every time you see a B, it means that the substring from 0 to that B (right open) must be reversed 
// in order to be "re-reversed" to match the answer, and then your next problem is to see if you can actually make that reversed string

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        string ans = "YES";
        int counter = t.length() - 1;
        while(true) {
            // breaking cases
            if (s.length() == counter + 1) {
                if (s == t.substr(0, s.length())) {
                    cout << "YES" << '\n';
                    break;
                } else {
                    cout << "NO" << '\n';
                    break;
                }
            }
            if (t[counter] == 'B') {
                reverse(t.begin(), t.begin() + counter);
            }
            --counter;
        }
    }
    return 0;
}