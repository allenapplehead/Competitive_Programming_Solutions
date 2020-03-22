#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    long double cur, prod = 0;
    cin >> n;
    while (n--) {
        cin >> cur;
        prod += log(cur);
    }
    prod = prod / log(2) + 1;
    cout << (long long) floor(prod) << "\n";
    return 0;
}