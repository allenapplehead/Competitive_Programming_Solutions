#include <bits/stdc++.h>
using namespace std;

// simluate the process from 0 - n - 1 (indices 0 indexed)
// because once you have the first number in a you can solve for the 2nd and it continues
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<int> ans(n);
    //vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    // just, simulate the process
    ans[0] = ar[0];
    int prev = 0;
    for (int i = 1; i < n; ++i) {
        ans[i] = max(prev, ans[i - 1]) + ar[i];
        prev = max(prev, ans[i - 1]);
    }
    // print
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}