#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp [3001][3001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int L = N - 1; L >= 0; L--) {
        for (int R = L; R < N; R++) {
            if (L == R) {
                dp[L][R] = arr[L];
            } else {
                dp[L][R] = max(arr[L] - dp[L + 1][R], arr[R] - dp[L][R - 1]);
            }
        }
    }
    cout << dp[0][N - 1] << "\n";
    return 0;
}