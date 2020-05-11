#include <bits/stdc++.h>

using namespace std;

vector<int> l;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
    }
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << i << "\n";
        } else {
            cout << i << " ";
        }
    }
    return 0;
}