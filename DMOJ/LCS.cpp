#include<bits/stdc++.h> 
using namespace std;

int dp[3002][3002];
int n1, n2;
//string a, b;
char a[3002], b[3002];
int main() {
    scanf("%s %s", &a, &b);
    n1 = (int) strlen(a);
    n2 = (int) strlen(b);
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1; 
            }
            // move right
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            // move down
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    // backtrack
    int idx = dp[n1][n2];
    char ans[idx + 1];
    ans[idx] = '\0';
    int i = n1, j = n2;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans[idx - 1] = a[i - 1];
            i--; j--; idx--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;   
        } else {
            j--;
        }
    }
    printf("%s\n", ans);
    return 0;
}