#include <bits/stdc++.h>
using namespace std;

// allen, you make so many stupid mistakes go kill yourself
// ONE: in the loops, you set it to loop 2 times instead of n times, good job 
// TWO: difference does not have to be 2, just has to be divisible by 2 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        // cover edge case
        if (n == 1) {
            cout << "YES" << '\n';
            continue;
        }
        string ans = "YES";
        for (int i = 1; i < n; ++i) {
            if (abs(ar[i] - ar[i - 1]) % 2 != 0) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}