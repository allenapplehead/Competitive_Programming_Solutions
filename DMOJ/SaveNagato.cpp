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

vector<vi> adj(500001); // adjacency list
bitset<500001> visited; // which nodes we visited
vi parent(500001); // parent[vertex] stores the parent of vertex
vi dp(500001); // storing distance down
vi dp2(500001); // storing distance up
int p, t = 0, depth = 0; // the previous node before we calculate the parent

// computes all distances from each node to the root recursively
int dfsDown (int vertex) {
    int maxPath = 0, cur = -1;
    if (visited[vertex] == false) {
        visited[vertex] = true;
        for (int i = 0; i < adj[vertex].size(); i++) {
            if (visited[adj[vertex][i]] == false) {
                parent[adj[vertex][i]] = vertex;
                cur = dfsDown(adj[vertex][i]);
                if (cur > maxPath) {
                    maxPath = cur;
                }
            }
        }
        if (cur == -1) {
            // we encountered a leaf
            dp[vertex] = 0;
            return 0;
        }
        dp[vertex] = maxPath + 1;
        return maxPath + 1;
    }
    return 0;
}

// compute the max distance not including the downward distance
int dfsUp (int vertex, int t) { // vertex is a parent!
    // blindly compute first, then check what it has done, and decide whether or not to keep going
    int f;
    t++; // we went up one
    int cur = -1, maxPath = 0;
    if (vertex == 0) {
        if (p == 0) {
            // we are at the root
            dp2[vertex] = 1;
            cout << "Case 1 => update: " << dp2[vertex] << ln;
            return 1;
            depth++;
        }
        
        if (dp2[vertex] != 0) {
            for (int i = 0; i < adj[0].size(); i++) {
                if (adj[0][i] != p) {
                    cur = dp[adj[0][i]] + 1;
                    if (cur > maxPath) {
                        maxPath = cur;
                    }
                }
            }
            if (depth) {
                depth++;
            }
            watch(dp2[vertex]);
            dp2[vertex] = max(dp2[parent[vertex]], depth + maxPath);
            cout << "Case 2 => update: " << dp2[parent[vertex]] << " " << depth + maxPath << ln;
            return t + maxPath;
        } else {
            return dp2[vertex] + t;
        }
        
          
        
    } else {
        for (int i = 0; i < adj[vertex].size(); i++) {
            if (adj[vertex][i] != p && adj[vertex][i] != parent[vertex]) {
                // traverse the children that is not the children we just traversed
                cur = dp[adj[vertex][i]] + 1;
                if (cur > maxPath) {
                    maxPath = cur;
                }
            }
        }
        if (depth) {
            depth++;
        }
        watch(dp2[vertex]);
        dp2[vertex] = max(dp[parent[vertex]], depth + maxPath);
        cout << "Case 3 => update: " << dp2[parent[vertex]] << " " << depth + maxPath << ln;
        
        p = vertex;
        f = dfsUp(parent[vertex], t);
        
        return max(t + maxPath, f);
    }
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
    int f;

    for (int i = 0; i < N; i++) {
        t = 0;
        f = dfsUp(i, 0);
        //cout << f << " " << dp[i] + 1 << ln;
        cout << max(f, dp[i] + 1) << ln;
    }
    cout << "fjdsklfjdsklfjdskl" << ln;
    for (int i = 0; i < 5; i++) {
        cout << dp2[i] << ln;
    }
    
    return 0;
}