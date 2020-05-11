#include <bits/stdc++.h>
 
using namespace std;
 
// read editorial, use COMBINATORICS, precompute factorials, and chill

const int N = 200005;
const int MOD = 998244353;
 
int add(int x, int y)
{
    x += y;
    return x > 0 ? x % MOD : x % MOD + MOD;
}
 
int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}
 
int binpow(int x, int y)
{
    // a different implementation of fastpow that bypasses 2 ^ -1 by not throwing an error when it hits there
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}
 
int inv(int x)
{
    return binpow(x, MOD - 2); // fermat's little theorem for division with modulus
}
 
int divide(int x, int y)
{
    return mul(x, inv(y)); // inverse elements are needed because division with modulus does not work
}
 
int fact[N];
 
void precalc()
{
    // precomute the factorials
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}
 
int C(int n, int k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
 
int main() 
{
    precalc();
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if(n > 2)
        ans = mul(C(m, n - 1), mul(n - 2, binpow(2, n - 3)));
    cout << ans << '\n';
}