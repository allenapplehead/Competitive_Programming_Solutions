#include <bits/stdc++.h>
using namespace std;

long long N, query;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    while (N--) {
        cin >> query;
        if (query & (query - 1) == 0) {
            cout << "T" << "\n";
        } else {
            cout << "F" << "\n";
        }
    }
    return 0;
}