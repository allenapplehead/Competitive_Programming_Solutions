#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a % b == 0) {
            cout << 0 << '\n';
        } else if (a < b) {
            cout << b - a << '\n';
        } else {
            cout << b - a % b << '\n';
        }
    }
    return 0;
}