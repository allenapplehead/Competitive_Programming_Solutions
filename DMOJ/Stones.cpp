#include <bits/stdc++.h>
using namespace std;

int n, k; // how many stones are left
bool dp[100005];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if ( i - a[j] >= 0 && dp[i - a[j]] == false) {
                dp[i] = true;
            }
        }
    }
    puts(dp[k] ? "First" : "Second");
    return 0;
}