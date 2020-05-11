#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int Q, y, z;
    cin >> Q;
    while (Q--) {
        cin >> y >> z;
        double low = 0.0, high = 100010.0, mid = 0.0;
        while (high - low >= 10e-6) {
            double res = 1.0;
            mid = static_cast<double>((low + high) / 2);
            // treat mid as x
            for (int i = 0; i < y; i++) {
                res = pow(mid, res);
                if (res > z) break;
            }
            if (res > z) high = mid;
            else low = mid;
        }
        cout << fixed << setprecision(10) << mid << "\n";
    }
    return 0;
}