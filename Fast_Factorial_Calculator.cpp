#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef unsigned long long ull;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define FOR(i, b) REP(i, 0, b)
#define pb push_back
#define mp make_pair
#define ln '\n'
#define watch(x) cout << (#x) << " is " << (x) << ln

const int INF = 1e9 + 5;
const double pi = 2 * acos(0.0);

template <typename T> void max_self(T& a, T b) {
    a = max(a, b);
}

template <typename T> void min_self(T& a, T b) {
    a = min(a, b);
}
ull N, cur, fact[34], ans = 1;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output.txt", "w", stdout); */
    
    cin >> N;
    fact[0] = 1;
    
    for (int i = 1; i < 34; i++) {
        fact[i] = (fact[i - 1] * i) % 4294967296;
        //watch(fact[i]);
    }

    while(N--) {
        cin >> cur;
        if (cur >= 34) {
            cout << 0 << ln;
        } else {
            cout << fact[cur] << ln;
        }
    }
    
    return 0;
}