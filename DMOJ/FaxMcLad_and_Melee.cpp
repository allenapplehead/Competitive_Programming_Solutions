#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 80; i++) {
        if (i % 4 == 0) {
            cout << "Illusion Attack" << "\n";
        } else {
            cout << "Fast Laser Blast" << "\n";
        }
    }
    return 0;
}