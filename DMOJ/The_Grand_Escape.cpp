#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//https://brilliant.org/wiki/linear-diophantine-equations-one-equation/
//https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

ll gcdExtended(ll a, ll b, ll *x, ll *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1; // To store results of recursive call  
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<ll> sols;
    for (int i = 0; i < n; ++i) {
        ll g;
        cin >> g;
        // 1 is the gcd of 2654435761 and 2^32 because the prior is prime
        ll d = 1;
        // since 1 % n == 1 the given equation will always have infinite equations
        ll a = 2654435761;
        ll b = 4294967296;
        // we are looking for i, which is the coefficient of a
        ll x, y;
        ll gcd_useless = gcdExtended(a, b, &x, &y);
        //cout << x << " " << y << '\n';
        ll res = (x * g) % 4294967296;
        sols.push_back(res);
    }
    sort(sols.rbegin(), sols.rend());
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ans += sols[i];
    }
    cout << ans << '\n';
    return 0;
}