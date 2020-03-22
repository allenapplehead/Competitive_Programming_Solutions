#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long x, m;
    cin >> x >> m;
    for (int i = 1; i < m; i++) {
        if (i * x % m == 1) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No such integer exists." << '\n';
    return 0;
}