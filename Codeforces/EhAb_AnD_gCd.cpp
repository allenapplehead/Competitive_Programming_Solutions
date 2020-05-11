#include <bits/stdc++.h>
using namespace std;

// realize that the answer is just 1 and x - 1
// how I got here is thru crunching out some of the numbers myself (like 2 and 3 and 4)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << x - 1 << " " << 1 << '\n';
    }
    return 0;
}