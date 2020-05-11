#include <bits/stdc++.h>
using namespace std;

// the editorial carried me, i was too stupid too realize how easy a problem this is
// if you look carefully at the input, you will notice the grid generated is very simple
// the array "a" being either 1 or zero gives only two possiblities for each row: either they are equal to b or they are all 0
// we can skip over the case where they are all zero
// this allows to count how many difference rows (number of rows) and columns (number of columns) there are, as we know they will only form rectangles and no irregular weird other shape thingies
// so we just find number of possiblities that yield a particular height or width and add them together

typedef long long ll;

vector<ll> g(vector<int> a) {
    int n = a.size();
    vector<ll> res(n + 1);
    int i = 0;
    while (i < n) {
        if (a[i] == 0) {
            i++;
            continue;
        }

        int j = i;
        while (j < n && a[j] == 1) {
            j++;
        }
        for (int len = 1; len <= j - i; ++len) {
            res[len] += j - i - len + 1;
        }
        i = j;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }

    ll ans = 0;

    vector<ll> ga = g(a);
    vector<ll> gb = g(b);

    for (int i = 1; i < ga.size(); ++i) {
        if (k % i == 0 && k / i <= m) {
            ans += ga[i] * gb[k / i];
        }
    }

    cout << ans << '\n';
    
    return 0;
}