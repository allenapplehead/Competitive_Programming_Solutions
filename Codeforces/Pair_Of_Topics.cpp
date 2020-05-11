#include <bits/stdc++.h>
using namespace std;

// i had the right idea - i suck at implementing it
// basically you binary search the lower bound for each value 1 to n - 2
// this way you do not have to sum each possibility one by one, but rather you can add large groups at a time
// you had trouble with negatives: just manipulate the equation math nerd
// editorial also did a really elegant way of making sure we are always taking the bigger value and searching for a smaller one (1st condition)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    // grab teacher values
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // grab student values
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // just a two pointer problem 
    vector<long long> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end());

    long long ans = 0;
    
    // binary search yourself the answer
    for (int i = 0; i < n; ++i) {
        if (c[i] <= 0) continue;
        int j = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
        ans += i - j;
    }

    cout << ans << '\n';

    return 0;
}