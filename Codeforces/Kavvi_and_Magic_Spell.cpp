#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 998244353;
 
void fix(int &x) { // interesting because it works just like a MOD and &x actually changes the variable
    if (x >= MOD) {
        x -= MOD;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    char s[1000005], t[1000005];
    cin >> (s + 1) >> (t + 1);
    // you have s and you are trying to make t
    int slen = strlen(s + 1); int tlen = strlen(t + 1);
    int ans = 0;
    vector<vector<int>> dp(slen + 1, vector<int>(slen + 1, 0));

    // intialization loop //
 
    for (int i = tlen; i <= slen; ++i) { // this loop just finds the starting points on what are some possible FIRST moves 
        if (i > tlen || s[i] == t[tlen]) { // condition 1: when the prefix already matches so the rest of the characters added to right does not matter
            dp[i][0] = 1; // execute OR non-excute: in how many ways can we make RIGHT moves
        }
        if (s[i] == t[1]) { // condition 2: if the last L move (which adds to the left thus the front) equals the first letter of the target hence t
            dp[i][1] = 1; // we can choose to execute this left move (and thus ignore the rest)
        }
    }
 
    // main dynamic programming routine //

    for (int i = slen; i > 1; --i) {                                // iterate through the seed string (generator string) BACKWARDS (rationale as that the first R's and L's detected will always be at the edges)
        for (int j = 0; j <= slen - i + 1; ++j) {                   // try all possible numbers of right moves when scanned the string from [i, slen]
            if (j + 1 > tlen || s[i - 1] == t[j + 1]) {             // either the number of left moves makes the string bigger than the target (given that the prefixes match) so it does not matter how we add the rest, but if not, you better make sure it matches
                dp[i - 1][j + 1] += dp[i][j];                       // performed a left move
                fix(dp[i - 1][j + 1]);                              // mod it
            }
            // j + i - 1 is the position of R
            if (j + i - 1 > tlen || s[i - 1] == t[j + i - 1]) {     //.the position of the R move can be found with j + i - 1, because since R's go on the right end, all the L moves (j) and the remaining moves buffer this R move up to the right side (rmbr not every move needs to be used)
                dp[i - 1][j] += dp[i][j];                           // performed a right move
                fix(dp[i - 1][j]);                                  // mod it
            }
        }
    }

    for (int j = 0; j <= slen; ++j) {
        ans += dp[1][j];
        fix(ans);
    }
    cout << ans << '\n';
    return 0;
}