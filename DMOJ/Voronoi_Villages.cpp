#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long double> ar(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    // borders are never the smallest villages
    // go through each pair of villages and try to find the smallest difference
    sort(ar.begin(), ar.end());
    long double minDifference = 1e18;
    int minDifstart = -1e9, minDifend = -1e9;
    for (int i = 2; i < n; ++i) {
        if (ar[i] - ar[i - 2] < minDifference) {
            minDifference = ar[i] - ar[i - 2];
            minDifstart = i - 2;
            minDifend = i;
        }
    }
    // find the midpoints of each pair
    long double mid1 = (ar[minDifstart] / 2 + ar[minDifstart + 1] / 2);
    long double mid2 = (ar[minDifend] / 2 + ar[minDifend - 1] / 2);
    long double why = mid2 - mid1;
    long double ans = round(why * 10.0) / 10.0;
    cout << std::fixed << std::setprecision(1) << ans << '\n';
    return 0;
}