#include <bits/stdc++.h>
using namespace std;

vector<int> dp (10001, 1e9);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int d, c;
    cin >> d;
    cin >> c;
    vector<int> clubs(c);
    for (int i = 0; i < c; i++) {
        cin >> clubs[i];
    }
    // main routine
    dp[0] = 0;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < clubs.size(); j++) {
            dp[i + clubs[j]] = min(dp[i + clubs[j]], dp[i] + 1);
        }
    }
    if (dp[d] != 1e9)
        cout << "Roberta wins in " << dp[d] << " strokes." << '\n';
    else
        cout << "Roberta acknowledges defeat." << '\n';
    return 0;
}