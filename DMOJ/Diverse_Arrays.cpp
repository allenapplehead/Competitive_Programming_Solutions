#include <bits/stdc++.h>
using namespace std;

int K, N, arr[1000001], f[1000001], l = -1, r = -1, c = 0; // c is for frequency table
long long ans = 0;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // 2 pointer!
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    while (l < N && r < N) {
        if (c < K) {
            // it is still diverse
            if (++f[arr[++r]] == 1) {
                // if we discovered a new number
                c++;
            }
        } else {
            // it is not diverse anymore, make it so, now, or ill die
            ans += N - r; // bc the current subarray is diverse, if we keep adding more elements on the back of it, it will also be diverse, so add that
            if (--f[arr[++l]] == 0) {
                // if we chop off the last element, will it cure?
                c--;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}