#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
// states: index odds left

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int evens = n / 2;
    int odds = n - evens;
    vector<int> ar(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        ar[i] == 0 ? ar[i] = -1;
        ar[i] = ar[i] % 2;
        ar[i] % 2 == 1 ? odds-- : evens--;
    }
    // greedily exploit the borders
    int l = 1e9, r = 1e9, ctr = 0;
    for (int i = 0; i < n; ++i) {
        if (ar[i] == -1) {
            ctr = 1;
            if (i == 0) l == -1;
            else {
                l = ar[i - 1];
            }
        } else {
            ctr = 0;
            if (ar[i] == l) {
                // same border, greedily fill these first
                if (ar[i] % 2 == 1) {
                    
                }
            }
        }

    }
    
    return 0;
}