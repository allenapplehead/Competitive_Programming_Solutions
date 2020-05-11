#include<bits/stdc++.h>
using namespace std;

// read the ed
// make sure all the subsequences are all increasing

void solve() {
    int n;
    cin >> n;
    vector<int> p(n); // the array itself
    for (int& i : p)
        cin >> i;
    vector<int> pos(n); // the order in which the elements come (o indexed)
    for (int i = 0; i < n; ++i)
        pos[--p[i]] = i;
    vector<bool> was(n);
    for (int i = 0; i < n; ++i) {
        if (was[i])
            continue;
        int me = pos[i];
        while (me < n) {
            was[me] = 1;
            if (me + 1 == n) break; // reaches end of array
            if (was[me + 1]) break; // already solved 
            if (p[me + 1] == p[me] + 1) { // only avoid the No answer if the numbers are consecutive
                ++me;
                continue;
            }
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
 
int main() {
    int q;
    cin >> q;
    while (q--)
        solve();
}