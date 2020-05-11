#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<string> ar(3);
    for (int i = 0; i < 3; ++i) cin >> ar[i];
    // check if good
    sort(ar.begin(), ar.end());
    char a = ar[0][0];
    char b = ar[1][0];
    char c = ar[2][0];
    
    if (a - '0' + 1 == b - '0' && b - '0' + 1 == c - '0' && ar[0][1] == ar[1][1] && ar[1][1] == ar[2][1]) {
        cout << 0;
    } else if (ar[0] == ar[1] && ar[1] == ar[2]) {
        cout << 0;
    } else if (ar[0] == ar[1] || ar[1] == ar[2] || ar[0] == ar[2]) {
        cout << 1;
    } else if (b - a <= 2 && ar[1][1] == ar[0][1] || c - b <= 2 && ar[2][1] == ar[1][1] || c - a <= 2 && ar[2][1] == ar[0][1]) {
        cout << 1;
    } else {
        cout << 2;
    }
    return 0;
}