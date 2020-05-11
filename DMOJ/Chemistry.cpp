#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long double exp = log10l(n)/log10l(2.00000000000000);
    //cout << exp << endl;
    cout << ceil(exp / m) << '\n';
    return 0;
}