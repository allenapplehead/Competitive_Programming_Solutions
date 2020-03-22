#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, k; cin >> n >> k;
    long long mod = n % k;
    cout << (n>=k ? min(mod, k - mod) : k-n) << "\n";
    return 0;
}