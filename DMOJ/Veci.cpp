#include <bits/stdc++.h>
using namespace std;

vector<int> number;

int findNum () {
    int orig = 0;
    for (int mult = 1, i = 0; i < number.size(); i++) {
        orig += ((int)number[number.size() - i - 1]) * mult;
        mult *= 10;
    }
    return orig;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string q; int bf = 0, af;
    cin >> q;
    for (char c : q) {
        number.push_back((int)c - 48);
    }
    
    bf = findNum();
    next_permutation(number.begin(), number.end());
    af = findNum();
    if (af > bf) {
        cout << af << "\n";
    } else {
        cout << 0 << "\n";
    }
    return 0;
}