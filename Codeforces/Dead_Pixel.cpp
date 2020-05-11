#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        int ans = 0;
        int length = max(x, a - x - 1);
        int height = max(y, b - y - 1);
        cout << max(length * b, a * height) << '\n';
    }
    return 0;
}