#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        // find if n can be represented as the sum of k odd ints
        if (k * k <= n && n % 2 == k % 2) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}