#include <bits/stdc++.h>
using namespace std;

long double choices[25][3];
long double ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long double ca, sa, pa;
    cin >> ca >> sa >> pa;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> choices[i][0] >> choices[i][1] >> choices[i][2];
    }
    // brute force all possibilities
    long double c = 0, s = 0, p = 0;
    long double r;
    n = 25;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (j == k || i == k) continue;
                for (int l = 0; l < n; l++) {
                    if (k == l || j == l || i == l) continue;
                    for (int m = 0; m < n; m++) {
                        r = 1e9;
                        if (l == m || k == m || j == m || i == m) continue;
                        c = choices[i][0] + choices[j][0] + choices[k][0] + choices[l][0] + choices[m][0];
                        s = choices[i][1] + choices[j][1] + choices[k][1] + choices[l][1] + choices[m][1];
                        p = choices[i][2] + choices[j][2] + choices[k][2] + choices[l][2] + choices[m][2];
                        if (c / ca < r) r = c / ca;
                        if (s / sa < r) r = s / sa;
                        if (p / pa < r) r = p / pa;
                        ans = max(ans, r);
                    }
                }
            }
        }
    }
    ans = ans * 100;
    if (ans > 100) ans = 100;
    cout << setprecision(1) << fixed << ans << '\n';
    return 0;
}