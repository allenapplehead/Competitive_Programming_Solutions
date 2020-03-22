#include <bits/stdc++.h>
using namespace std;

int N, p[500001], l[500001];
long long ans = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> p[i];
    for (int j = 0; j < N; j++) cin >> l[j];

    sort(p, p + N);
    sort(l, l + N, greater<int>());

    for (int i = 0; i < N; i++) {
        ans += p[i] * l[i];
    }
    cout << ans << "\n";
    return 0;
}