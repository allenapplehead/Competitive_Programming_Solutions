#include <bits/stdc++.h>
using namespace std;

// heres the thing
// you realize that the best answer contains two factors (ie the two numbers sum to x):
// 1: how many pairs will only need 1 element changed in order to sum to this (minimize this)
// 2: how many pairs are already at this sum (maximize this)
// to do this, run thru both of these and calculate it in O(n)
// how? the first part is trivial (just a frequency array)
// the second part is more subtle: identify the upper and lower limits where meeting this sum x only required changing 1 element
// use an array to hold these bounds (indicating the range [l, r + 1)) will indicate a pair exists such that an x belonging in that set will satisfy the above rule
// and then, just prefix sum this! which will get u pref[x] is the number of pairs where meeting sum x only requires changing one element

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        vector<int> cnt(2 * k + 1);
        for (int i = 0; i < n / 2; ++i) {
            cnt[ar[i] + ar[n - i - 1]]++;
        }
        vector<int> pref(2 * k + 2);
        // so big brain 
        for (int i = 0; i < n / 2; ++i) {
            // min and max sum such that we only need to change 1 element in this pair to make this sum:
            // min(a, b) + 1
            // max(a, b) + k
            int l1 = ar[i] + 1, r1 = ar[i] + k;
            int l2 = ar[n - i - 1] + 1, r2 = ar[n - i - 1] + k;
            pref[min(l1, l2)]++;
            pref[max(r1, r2) + 1]--;
        }
        for (int i = 1; i <= 2 * k + 1; ++i) {
            pref[i] += pref[i - 1];
        }
        // in the end, pref[x] should tell us the number of pairs that we need to replace at most one element in this pair to make it sum to x

        // // debug
        // for (int i = 0; i < 2 * k + 2; ++i) {
        //     cout << pref[i] << ' ';
        // }
        // cout << '\n';
        int ans = 1e9;
        for (int sum = 2; sum <= 2 * k; ++sum) {
            ans = min(ans, (pref[sum] - cnt[sum]) + (n / 2 - pref[sum]) * 2);
            //            how many times we add 1 + how many times we add 2
        }
        cout << ans << '\n';
    }
    return 0;
}