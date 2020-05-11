#include <bits/stdc++.h>
using namespace std;

// just express all side lengths algebraically

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    // xy = a
    // yz = b
    // xz = c
    int x = sqrt((a * c) / b);
    int y = a / x;
    int z = b / y;
    cout << (x + y + z) * 4 << '\n';

    return 0;
}