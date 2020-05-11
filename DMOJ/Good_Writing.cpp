#include <bits/stdc++.h>
using namespace std;

string base = "Good writing is good writing is good writing.";
string sec1 = "Good writing is good ";
string sec2 = " writing is good ";
string sec3 = " is good writing.";
int section = sec1.length() + sec2.length() + sec3.length();

char solve(int n, int k) {
    if (!n) {
        if (k <= base.length()) {
            return base[k - 1];
        } else {
            return '.';
        }
    }
    if (k <= sec1.length()) {
        return sec1[k - 1];
    } else if (k <= sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length())) {
        return solve(n - 1, k - sec1.length());
    } else if (k <= sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec2.length()) {
        return sec2[k - (sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length())) - 1];
    } else if (k <= sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec2.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length())) {
        return solve(n - 1, k - (sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec2.length()));
    } else if (k <= sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec2.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec3.length()) {
        return sec3[k - (sec1.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length()) + sec2.length() + (pow(2, n - 1) - 1) * section + (pow(2, n - 1) * base.length())) - 1];
    } else {
        return '.';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    return 0;
}