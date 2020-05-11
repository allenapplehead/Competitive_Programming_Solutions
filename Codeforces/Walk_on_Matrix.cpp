//https://codeforces.com/problemset/problem/1332/D
#include <bits/stdc++.h>
using namespace std;

// editorial does a pretty good job

typedef long long ll;

// force the matrix to output zero based on the dp

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    // generate a matrice
    ll x = pow(2, 17);
    cout << 2 << " " << 3 << '\n';
    cout << (x ^ k) << " " << x << " " << 0 << '\n';
    cout << k << " " << (x ^ k) << " " << k << '\n';    
    return 0;
}