#include <bits/stdc++.h>
using namespace std;

// notes:
// using mp[] is magical
// ok I finally understand the problem with no editorial dab
// so bascially, there are two cases where a subarray can become 0
// case 1: there is the element 0 itself
// case 2: the elements cancel each other out at some point
// this sneaky second case can be detected using a prefix sum array, when two values of a prefix sum array equal to each other
// so all you have to do to solve this problem is to keep track of where you seen what

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long long> ps(n + 1);
    map<long long, int> mp;
    ps[0] = 0;
    for (int i = 0, g; i < n; ++i) {
        cin >> g;
        ps[i + 1] = ps[i] + g;
    }
    int l = 0;
    mp[0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        cout << i << " " << ps[i] << " " << l << '\n';
        if (mp.find(ps[i]) != mp.end()) l = max(l, mp[ps[i]] + 1);
        ans += i - l;
        mp[ps[i]] = i;
    }
    cout << ans << '\n';

    return 0;
}