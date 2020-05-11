#include <bits/stdc++.h>
using namespace std;

// the answer is just a min between the sum of the array and the max value

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ar(n);
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
            tot += ar[i];
        }
        cout << min(m, tot) << '\n';
    }
    return 0;
}