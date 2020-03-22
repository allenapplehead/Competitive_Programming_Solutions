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

template <typename T>
void max_self(T &a, T b)
{
    a = max(a, b);
}

template <typename T>
void min_self(T &a, T b)
{
    a = min(a, b);
}

vector<vi> adj(500001);
vi parents(500001);
vi dp(500001);
bitset<500001> visited;
int prevNode, t; // for calculating up

// pre calculate all the distances DOWN (to leaves)
int dfsDOWN(int vertex)
{
    int vCount = 0, maxPath = 0, cur = 0;
    vi paths;
    //watch(vertex);
    if (visited[vertex] == false)
    {
        visited[vertex] = true;
        for (int i = 0; i < (int)adj[vertex].size(); i++)
        {
            if (visited[adj[vertex][i]])
            {
                vCount++;
            }
            else
            {
                parents[adj[vertex][i]] = vertex;
                if (visited[adj[vertex][i]] == false) {
                    cur = dfsDOWN(adj[vertex][i]);
                }
                
                if (cur > maxPath)
                {
                    maxPath = cur;
                }
            }
        }
    }

    if (vCount == adj[vertex].size())
    {
        // it is a leaf
        dp[vertex] = 0;
        return 0;
    }
    else
    {
        dp[vertex] = maxPath + 1;
        return maxPath + 1;
    }
}

// calculate distances UP recursively
int dfsUP(int vertex)
{
    // find the parent, and stop after having calculated the ROOT
    //watch(vertex);
    int nxtUp, cur, maxPath = -2, ran = 0, maxi = 0;
    prevNode = vertex;
    nxtUp = parents[vertex];
    t++;
    for (int i = 0; i < adj[nxtUp].size(); i++)
    {
        if (adj[nxtUp][i] != prevNode && parents[nxtUp] != adj[nxtUp][i])
        {
            ran++;
            //cout << "SCREEE " << adj[nxtUp][i] << " " << prevNode << ln;

            cur = dp[adj[nxtUp][i]];
            if (cur > maxPath)
            {
                maxPath = cur;
            }
        }
    }
    
    if (nxtUp == 0) {
        for (int i = 0; i < adj[0].size(); i++) {
            if (adj[0][i] != prevNode && prevNode != 0) {
                cout << "gay" << ln;
                if (dp[adj[0][i] > maxi]) {
                    maxi = dp[adj[0][i]];
                }
            }
        }
        return t + maxi;
    }
    return max(1 + dfsUP(nxtUp), 2 + maxPath);

}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* freopen("leapfrog_ch_.txt", "r", stdin);*/
    //freopen("output.txt", "w", stdout);
    int N, start, end;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> start >> end;
        adj[start - 1].pb(end - 1);
        adj[end - 1].pb(start - 1);
    }
    dfsDOWN(0);
    for (int i = 0; i < N; i++)
    {
        cout << dp[i] << ln;
    }
    int f;
    for (int i = 0; i < N; i++)
    {
        t = 1;
        f = dfsUP(i);
        cout << f << " " << 1 + dp[i] << ln;
        cout << max(f, 1 + dp[i]) << ln;
    }
    return 0;
}