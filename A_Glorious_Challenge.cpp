#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int temp, i = 0; i < n; i++) {
        cin >> temp;
        a[i] = temp + i;
        b[i] = temp - i;
    }
    long long ans1, ans2;
    ans1 = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    ans2 = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end());
    cout << max(ans1, ans2) << '\n';
    return 0;
}