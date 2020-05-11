#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, z = 0, o = 0, ans = 1;
    string code;
    vector<string> subs;
    cin >> N;
    cin >> code;
    for (int i = 0; i < N; i++) {
        if (code[i] == '0') {
            z++;
        } else {
            o++;
        }
    }
    if (z != o) {
        // the string is good
        cout << "1\n";
        cout << code << "\n";
    } else {
        cout << "2\n";
        cout << code.substr(0, code.length() - 1) << " " << code[code.length() - 1] << "\n";
    }
    return 0;
}