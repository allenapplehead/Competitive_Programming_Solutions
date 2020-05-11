#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int OFFSET = 400005;

ll ind[400005 + OFFSET];

// basically, I coded an iterative dynamic programming solution that TLE'd
// realize that this is overkill for this problem
// if you rearrange the formula (yes, do this a lot) into the form ci - bi = cj - bj
// you will notice that for elements to be in the same trip the i - bi values must be equal
// an offset is used to avoid negative indices

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll g;
        cin >> g;
        ind[i - g + OFFSET] += g;
    }
    // rmbr that i - bi will always be consistent
    cout << *max_element(ind, ind + 400005 + OFFSET) << '\n';
    return 0;
}