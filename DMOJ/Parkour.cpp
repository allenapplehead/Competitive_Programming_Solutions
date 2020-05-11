#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long x, y, h, v, t;
    cin >> x >> y >> h >> v >> t;
    long long ans = 0, curx = 0, cury = 0;
    while (true) {
        // try to greedily minimize between the x and y distances
        //cout << curx << " "  << cury << '\n';
        ans++;
        if (ans >= t) break;
        if (curx + 1 >= x && curx + 1 < x + h && cury + 2 >= y && cury + 2 < y + v) break;
        if (curx + 2 >= x && curx + 2 < x + h && cury + 1 >= y && cury + 1 < y + v) break;
        if (x - curx < y - cury) {
            curx += 1;
            cury += 2;
        } else {
            curx += 2;
            cury += 1;
        }
        if (curx >= x && curx < x + h && cury >= y && cury < y + v) break;
    }
    if (ans < t) cout << "YES" << '\n';
    else  cout << "NO" << '\n';
    return 0;
}