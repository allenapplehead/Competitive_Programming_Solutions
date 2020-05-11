#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// i do not get this problem at all
// somehow you can big brain your way to get

// (KEY) a + b = a (xor) b + 2 * (a & b)

// nvm i get it
// editorial can go kill itself
// so basically after you proved u can always get three and covered all the edge cases
// to prove you can get two you need to see if the bits of u and x don't clash with each other (when u bitwise and them it does not return true)
// if they intermesh nicely then the other x will just cancel it out

// i still do not get how they prove that you only need to add u + x, why can't you try other sums?
// no ur stupid the xors need to cancel themselves out stooopid

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // look at special cases first
    // if u > v or u or v have different partiies, -1
    ll u, v;
    cin >> u >> v;

    if (u > v || u % 2 != v % 2) {
        cout << -1 << '\n';
    } else if (u == v && u == 0) {
        cout << 0 << '\n';
    } else if (u == v) {
        cout << 1 << '\n' << u << '\n';
    } else {
        ll x = (v - u) / 2;
        // try to make it two elements
        if(u&x) {
            cout << 3 << '\n' << u << " " << x << " " << x << '\n';
        } else {
            cout << 2 << '\n' << (u^x) << " " << x << '\n'; // the other part already kills itself by the condition
        }
    }
    return 0;
}