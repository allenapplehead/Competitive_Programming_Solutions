#include <bits/stdc++.h>
using namespace std;

vector<int> ctr(6);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, ans = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "red")
            ctr[0]++;
        else if (s == "orange")
            ctr[1]++;
        else if (s == "yellow")
            ctr[2]++;
        else if (s == "green")
            ctr[3]++;
        else if (s == "blue")
            ctr[4]++;
        else if (s == "black")
            ctr[5]++;
    }
    ans = *max_element(ctr.begin(), ctr.end());
    ans = min(ans, n - ans + 1) + n - ans;
    cout << ans << '\n';
    return 0;
}