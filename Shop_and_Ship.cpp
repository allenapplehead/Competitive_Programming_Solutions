#include <bits/stdc++.h>
using namespace std;

int N, T, x, y, C, K, z, P, D;

int dp[5005];
int AdjMat[5005][5005];
bitset<5005> visited;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(AdjMat, 0x3f3f3f3f, sizeof(AdjMat));
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    cin >> N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y >> C;
        AdjMat[x][y] = C;
        AdjMat[y][x] = C;
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> z >> P;
        dp[z] = P;
    }
    // all pairs shortest path
    for (int i = 0; i < N; i++) {
        int cur = 0;
        for (int j = 1; j <= N; j++) {
            if (!visited[j] && dp[j] < dp[cur]) cur = j;
        }
        if (!cur) break;
        visited[cur] = true;
        for (int j = 1; j <= N; j++) {
            if (dp[cur] + AdjMat[cur][j] < dp[j]) dp[j] = dp[cur] + AdjMat[cur][j];
        }
    }
    cin >> D;
    cout << dp[D] << '\n';
    return 0;
}