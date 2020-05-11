#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> n >> m;
        n % m == 0 ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}