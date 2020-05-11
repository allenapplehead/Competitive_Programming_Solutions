#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define LSOne(S) ((S) & -(S))
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

vector<vi> adj(1000001); // stores only paths down the tree

int bowls (int vertex) {
    // recurse down to the root
    int maxPath = 0, ptr = 0;
    vi posses;
    if (!adj[vertex].size()) {
        return 1; // doesn't depend on anything else
    }

    for (int temp, i = 0; i < (int)adj[vertex].size(); i++) {
        temp = bowls(adj[vertex][i]);
        posses.pb(temp);
    }

    sort(posses.begin(), posses.end(), greater<int>());
    for (int i = 1; i < posses.size(); i++) {
        if (posses[i] == posses[i - 1])
            ptr++;
    }
    return adj[vertex].size() + 1 >= posses[0] + ptr ? adj[vertex].size() + 1 : maxPath;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); */
    int n, temp, ans;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        adj[temp - 1].pb(i);
    }

    ans = bowls(0);
    cout << ans << ln;
    return 0;
}