#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* freopen("leapfrog_ch_.txt", "r", stdin);
	freopen("output.txt", "w", stdout); */
    int N;
    bool prime = false;
    cin >> N;
    if (N <= 2) {
        cout << 2 << ln;
        return 0;
    } else if (N == 3) {
        cout << 3 << ln;
        return 0;
    };
    while(!prime) {
        prime = true;
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                N++;
                //watch(N);
                prime = false;
                break;
            } 
        }
    }
    
    cout << N << ln;
    
    return 0;
}