#include <bits/stdc++.h>
using namespace std;

// used editorial (its a good one)

// basically, the reason why I didn't get this problem over the summer is because of the following test:
// DDDAAA
// you have to write a function to see if it is even possible to minimize in the x or y direction, because 
// you can not treat the mins and maxes of the arrays separately as they are intertwined
// ie, if you mitigate the max by moving to the left you might increase the min
// so to do this you must check their order thats all

typedef long long ll;

bool solve(vector<ll> ps, bool sign) {
    // if sign is positive then we are moving in the positive direction

    // find the lastMax and firstMin
    if (sign) {
        ll lastMax = -1e9, firstMin = -1e9;
        ll mx = 0, mn = 0;
        for (int i = 1; i < ps.size(); ++i) {
            if (ps[i] >= mx) {
                mx = ps[i];
                lastMax = i;
            }
            if (ps[i] < mn) {
                mn = ps[i];
                firstMin = i;
            }
        }
        if (lastMax < firstMin) return true;
        else return false;
    } else {
        ll lastMin = -1e9, firstMax = -1e9;
        ll mx = 0, mn = 0;
        for (int i = 1; i < ps.size(); ++i) {
            if (ps[i] > mx) {
                mx = ps[i];
                firstMax = i;
            }
            if (ps[i] <= mn) {
                mn = ps[i];
                lastMin = i;
            }
        }
        if (lastMin < firstMax) return true;
        else return false;
    }
        
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // split into two arrays
        vector<ll> a;
        vector<ll> b;
        a.push_back(0);
        b.push_back(0);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'W' || s[i] == 'S') {
                a.push_back(a[a.size() - 1] + (s[i] == 'W' ? 1 : -1));
            } else {
                b.push_back(b[b.size() - 1] + (s[i] == 'D' ? 1 : -1));
            }
        }

        ll dima = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) + 1;
        ll dimb = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end()) + 1;

        // see if any of them are able to be minimized
        ll mina = 0, minb = 0;
        if ((solve(a, true) || solve(a, false)) && dima > 2) {
            mina = 1;
        }
        if ((solve(b, true) || solve(b, false)) && dimb > 2) {
            minb = 1;
        }

        if (mina && minb) {
            cout << (min(dima, dimb) - 1) * max(dima, dimb) << '\n';
        } else if (mina) {
            cout << (dima - mina) * dimb << '\n';
        } else if (minb) {
            cout << dima * (dimb - minb) << '\n';
        } else {
            cout << dima * dimb << '\n';
        }

        // // debug
        // for (int i = 0; i < a.size(); ++i) {
        //     cout << a[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < b.size(); ++i) {
        //     cout << b[i] << " ";
        // }
    }
    return 0;
}