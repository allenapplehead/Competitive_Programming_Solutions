#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, s, n, budget;
    bool found = false;
    cin >> N;
    while (N--) {
        found = false;
        cin >> s >> n >> budget;
        for (int i = 0; i <= budget; i+=s) {
            for (int j = 0; j <= budget - i; j += n) {
                if (i + j == budget) {
                    found = true;
                }
            }
        }
        if (found == false) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}