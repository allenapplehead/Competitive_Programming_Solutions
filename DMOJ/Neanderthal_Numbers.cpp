#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<string> words = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
int dp[MAXN][MAXN];
string word;

int solve(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    if (l > r) return 1; // base case
    int ans = 0;
    for (string w : words) {
        if (r - l + 1 >= w.length()) {
            string c = word.substr(l, w.length());
            if (c == w) {
                ans += solve(l + w.length(), r);
            }
        }
    }
    dp[l][r] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 10;
    while (t--) {
        cin >> word;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, word.length() - 1) << '\n';
    }
    return 0;
}