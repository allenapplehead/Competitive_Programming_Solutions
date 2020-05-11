#include <bits/stdc++.h>
using namespace std;

int N, V, c, l;
vector<int> coins;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> V;
    for (int temp, i = 0; i < N; i++) {
        cin >> temp;
        coins.push_back(temp);
    }
    for (int i = 0; i < V; i++) {
        cin >> c >> l;
        vector<int> scoins;
        bitset<10001> visited;
        visited.set();
        vector<int> dp (10001, 1000000000); 
        dp[0] = 0;
        for (int i = 0; i < l; i++) {
            if (visited[i])
                scoins.push_back(coins[i]);
            visited[i] = false; // we dont want duplicates
        }
        sort(scoins.rbegin(), scoins.rend());
        bool kill = false;
        int remainder, ans = 1e9;
        for (int i = 0; i < l; i++) {
            if (kill) break;
            // try to solve for max at a time
            for (int j = c / scoins[l]; j > 0; j--) {
                if (kill) break;
                // max it out
                remainder = c - scoins[l] * j;
                // dp the remainder to see if we can solve
                for (int k = 0; k < remainder; k++) {
                    if (kill) break;
                    if (dp[k] == 1000000000) continue;
                    for (int m = 0; m < l - i - 1; m++) {
                        if (k + scoins[m] > remainder) {
                            continue;
                        }
                        dp[k + scoins[m]] = min(dp[k] + 1, dp[k + scoins[m]]);
                    }
                }
                ans = c / scoins[i] + dp[remainder - 1];
                kill = true;
            }
        }
        if (ans != 1e9) {
            cout << ans << "\n";
        } else {
            cout << "-1" << "\n";
        }
    }
    return 0;
}