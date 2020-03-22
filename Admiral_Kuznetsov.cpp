#include <bits/stdc++.h>
using namespace std;

int dp[1000001]; // idx i represents commands up to that plane to reach final config
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, cnt, tgt; cin >> N;
    string b1, b2; cin >> b1 >> b2;
    
    // fill with INF
    for (int i = 1; i < N + 1; i++) {
        dp[i] = INF;
    }

    // main routine
    int counter = 0;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        // if they are equal
        if (b1[i] == b2[i]) {
            dp[i + 1] = min(dp[i + 1], dp[i]);
        }
        // if we can just land a plane with no clearing
        else if (b1[i] == '0') {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        // if we have to clear (1 turns into a 0)
        if (i - 2 >= 0) {
            // we can clear three
            cnt = count(b1.begin() + i - 2, b1.begin() + i + 1, '1');
            tgt = count(b2.begin() + i - 2, b2.begin() + i + 1, '1');
            dp[i + 1] = min(dp[i + 1], dp[i - 2] + (3 - cnt) + 1 + tgt);
            if (N == 5) {
                while (dp[i - 2 + counter] >= 1e9) {
                    counter++;
                }
                if (counter) {
                    cnt = count(b1.begin() + i - 1, b1.begin() + i + 1, '1');
                    tgt = count(b2.begin() + i - 1, b2.begin() + i + 1, '1');
                    dp[i + 1] = min(dp[i + 1], dp[i - 2 + counter] + counter + (2 - cnt) + 1 + tgt);
                    counter = 0;
                }
                
            }
        }
        if (i - 3 >= 0) {
            // we can clear four
            cnt = count(b1.begin() + i - 3, b1.begin() + i + 1, '1');
            tgt = count(b2.begin() + i - 3, b2.begin() + i + 1, '1');
            dp[i + 1] = min(dp[i + 1], dp[i - 3] + (4 - cnt) + 1 + tgt);
            if (N == 5) {
                while (dp[i - 3 + counter] >= 1e9) {
                    counter++;
                }
                if (counter) {
                    cnt = count(b1.begin() + i - 2, b1.begin() + i + 1, '1');
                    tgt = count(b2.begin() + i - 2, b2.begin() + i + 1, '1');
                    dp[i + 1] = min(dp[i + 1], dp[i - 3 + counter] + counter + (3 - cnt) + 1 + tgt);
                    counter = 0;
                } 
            }
        }
        if (i < 2) {
            // we are near the beginning
            dp[i + 1] = min(dp[i + 1], INF);
        }
    }

    /* for (int i = 0; i < N + 1; i++) cout << dp[i] << " ";
    cout << endl; */

    cout << dp[N] << "\n";
    return 0;
}