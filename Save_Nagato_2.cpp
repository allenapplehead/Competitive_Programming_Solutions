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

vector<vi> adj(500001); // adjacency list(2,vector<double>(2))
bitset<500005> visited; // which nodes we visited
vi parent(500005); // parent[vertex] stores the parent of vertex
vector<ii> dp(500005);
int dp2[500005];
int p;

// computes all distances from each node to the root recursively
int dfsDown (int vertex) {
    int maxPath = 0, otherPath = -1, cur = -1;
    if (visited[vertex] == false) {
        visited[vertex] = true;
        for (int i = 0; i < adj[vertex].size(); i++) {
            if (visited[adj[vertex][i]] == false) {
                parent[adj[vertex][i]] = vertex;
                cur = dfsDown(adj[vertex][i]);
                //cout << "[ * ] Vertex: " << vertex << ln;
                if (cur >= maxPath) {
                    if (adj[vertex].size() > 1) {
                        //cout << otherPath << " MIN--> " << maxPath << ln; 
                        otherPath = maxPath;
                        //cout << maxPath << " MAX--> " << cur << ln;
                        maxPath = cur;
                    } else {
                        //cout << maxPath << " MAX--> " << cur << ln;
                        maxPath = cur;
                    }
                    
                } else if (cur > otherPath && adj[vertex].size() > 1) {
                    otherPath = cur;
                }
            }
        }
        if (cur == -1) {
            // we encountered a leaf
            dp[vertex] = mp(0, -1);
            return 0;
        }
        dp.at(vertex) = mp(maxPath + 1, otherPath + 1);
        return maxPath + 1;
    }
    return 0;
}

// compute the max distance not including the downward distance
int dfsUp (int vertex) { // vertex is the child, t is the distance traversed
    int p, maxPath = -1, best, f;
    if (vertex == 0) {
        // we reached the root
        dp2[vertex] = 1;
        return 1;
    }
    if (dp2[vertex] != 0) {
        return dp2[vertex];
    }
    p = parent[vertex];
    
    if (dp[p].first == dp[vertex].first + 1) {
        //cout << "SECOND" << ln;
        maxPath = dp[p].second;
        //watch(maxPath);
    } else {
        //cout << "FIRST" << ln;
        maxPath = dp[p].first;
        //watch(maxPath);
    }
    /* for (int i = 0; i < adj[p].size(); i++) {
        if (adj[p][i] != vertex && adj[p][i] != parent[p]) {
            // traverse routes from vertex originating from parent that do not go through vertex itself
            if (dp[adj[p][i]] + 1 > maxPath) {
                maxPath = dp[adj[p][i]] + 1;
            }
        }
    } */
    f = dfsUp(p) + 1;
    best = max(maxPath + 2, f);
    //cout << "V: " << vertex << " P: " << p << ln;
    
    dp2[vertex] = best;
    return best;
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); */
    int N, u, v;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    dfsDown(0);

    /* for (int i = 0; i < 5; i++) {
        cout << dp[i].first << " " << dp[i].second << ln;
    }
    cout << "=========" << ln; */

    int f;
    for (int i = 0; i < N; i++) {
        if (dp2[i] == 0) {
            f = dfsUp(i);
        }
        //cout << dp2[i] << " " << dp[i].first + 1 << ln;
        cout << max(dp2[i], dp[i].first + 1) << ln;
    }
    
    return 0;
}