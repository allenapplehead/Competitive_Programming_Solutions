#include <bits/stdc++.h>
using namespace std;

int sol[1000005];
bitset<1000005> exists;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            exists[a[i]] = true;
        }
        // solve
        memset(sol, 0, sizeof(sol));
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n / i; j++) {
                if (exists[i * j] && i * j )
            }
        }
    }
    return 0;
}