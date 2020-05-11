#include <bits/stdc++.h>
using namespace std;

// pretty simple, make sure you are thorough on your cases ie if the favoured robot solves no problems at all its done for
// otherwise just do the casework, remembering that only the unique problems the robot solved from each other matter (ie common problems they both solve do not matter)
// breaking case: 1 0 1

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }
    int sma = 0, smb = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1 && b[i] != 1) {
            sma++;
        } else if (a[i] != 1 && b[i] == 1) {
            smb++;
        }
    }
    if (sma == 0) {
        cout << -1 << '\n';
    } else if (sma > smb) {
        cout << 1 << '\n';
    } else if (sma == smb) {
        cout << 2 << '\n';
    } else {
        cout << ceil((smb + 1.0) / sma) << '\n';
    }
    return 0;
}