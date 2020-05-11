#include <bits/stdc++.h>
using namespace std;

// rearrange into i - j != ai - aj
// and sort it in reverse so that you get negatives which are not possible
// bc since i - j will be negative as defined in the problem
// bc i < j, by sorting in reverse all the values u get are (-inf, 0]

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        sort(ar.rbegin(), ar.rend());
        for (int i = 0; i < n; ++i) {
            cout << ar[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}