#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, k;
    cin >> n;
    cin >> k;
    long long temp;
    temp = n % k;
    if (n % k == 0) {
        cout << 0 << "\n";
    } else if (k > n) {
        cout << k - n << "\n";
    } else {
        cout << min(temp, k - temp) << "\n";
    }
    return 0;
}