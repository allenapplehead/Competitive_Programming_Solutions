#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, f1, f2;
    cin >> n;
    string start, end;
    cin >> start >> end;
    // create base pattern for both
    int nOdd = 0, nEven = 0;
    for (int i = 0; i < n; i++) {
        if (start[i] == 'F') {
            if (i % 2 == 0) {
                nOdd++;
            } else {
                nEven++;
            }
        }
    }
    f1 = nOdd - nEven;
    nOdd = 0;
    nEven = 0;
    for (int i = 0; i < n; i++) {
        if (end[i] == 'F') {
            if (i % 2 == 0) {
                nOdd++;
            } else {
                nEven++;
            }
        }
    }
    f2 = nOdd - nEven;

    if (f1 == f2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}