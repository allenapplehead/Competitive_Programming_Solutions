#include <bits/stdc++.h>
using namespace std;

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    vector<vector<int>> dist(n, vector<int>(10)); // number of bits that need to be turned on to reach dist[x][y], where x is initial and y is final
    for (int i = 0; i < n; ++i) { // each line of input
        cin >> s[i];
        for (int d = 0; d < 10; ++d) { // each possible digit from 0 - 9
            for (int j = 0; j < 7; ++j) { // each bit 
                char x = s[i][j];
                char y = digits[d][j];
                if (x == '1' && y == '0') { // if the destination has a bit turned on that the digit does not, impossible
                    dist[i][d] = -1;
                    break;
                }
                if (x == '0' && y == '1') {
                    dist[i][d]++;
                }
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[n][0] = 1; // if at the suffix i ... n you can turn on exactly j sticks and get the correct seq
    for (int i = n; i > 0; --i) {
        for (int j = 0; j <= k; ++j) {
            if (dp[i][j]) {
                for (int d = 0; d < 10; ++d) {
                    if (dist[i - 1][d] != -1 && j + dist[i - 1][d] <= k) {
                        dp[i - 1][j + dist[i - 1][d]] = 1;
                    }
                }
            }
        }
    }
    if (dp[0][k] == 0) {
        cout << -1 << '\n';
        return 0;
    }
    // retraces the steps back up
    for (int i = 0; i < n; ++i) { // 0 is the first digit (highest value)
        int now = -1;
        for (int d = 9; d >= 0; --d) {
            if (dist[i][d] != -1 && k >= dist[i][d] && dp[i + 1][k - dist[i][d]]) {
                now = d;
                k -= dist[i][d];
                break;
            }
        }
        cout << now;
    }
    cout << '\n';
    return 0;
}