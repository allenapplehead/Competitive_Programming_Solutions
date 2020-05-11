#include <bits/stdc++.h>
using namespace std;

// really good problem, too bad I copied this solution from eric574

// his solution was essentially the editorial 
// basically, to understand this problem, you first need to understand the O(n^4) solution that does not use 2-pointers algorithm
// you need to be very thorough, so what do we have to loop?
// we must loop thru:
// * the interval sizes (gap)
// * where to start (l), thus where to end can be determined by sum of l + gap
// * define the right end of the left interval
// * define the left end of the right interval

// the last two loops could be optimized into 2 pointers, so you do not have to loop through every possibility
// because you can move with strats

int n, dp[405][405], ps[405], ans;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> dp[i][i];
        ans = max(ans, dp[i][i]);
        ps[i] = ps[i - 1] + dp[i][i];
    }

    for (int gap = 1; gap < n; ++gap) {
        for (int l = 1; l + gap <= n; ++l) {
            int r = l + gap;
            for (int i = l, j = r; i + 1 <= j;) {
                if (dp[l][i] && dp[j][r] && dp[l][i] == dp[j][r]) {
                    if (i + 1 == j) {
                        dp[l][r] = max(dp[l][r], dp[l][i] + dp[j][r]);
                    }
                    if (i + 1 < j && dp[i + 1][j - 1] != 0) {
                        dp[l][r] = max(dp[l][r], dp[l][i] + dp[i + 1][j - 1] + dp[j][r]);
                    }
                    ans = max(ans, dp[l][r]);
                }
                if (ps[i] - ps[l - 1] == ps[r] - ps[j - 1]) {
                    i++;
                    j--;
                } else if (ps[i] - ps[l - 1] < ps[r] - ps[j - 1]) i++;
                else j--;
            } 
        }
    }
    cout << ans << '\n';
    return 0;
}