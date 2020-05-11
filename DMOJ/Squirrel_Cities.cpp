#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, q, a, b;
ll d, t, x, y;

const int MAXN = 100005;
ll arr[MAXN];
ll sizes[MAXN];

int vis = 1;

// kruskal's
pair <pair<ll, ll>, pair<int, int>> p[MAXN]; // one million edges

void initialize(int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
        sizes[i] = 1;
    }
}

int find(int a, int b) {
    if (arr[a] == arr[b]) {
        return 1; // in the same disjoint set
    } else {
        return 0;
    }
}

int findParent(int i) {
    while (arr[i] != i) {
        arr[i] = arr[arr[i]]; // parent of the parent PATH COMPRESSION
        i = arr[i];
    }
    return i;
}

void Union(int a, int b) {
    int aSet = findParent(a);
    int bSet = findParent(b);
    if (sizes[aSet] > sizes[bSet]) {
        arr[aSet] = arr[bSet]; // merge the larger tree into the smaller, so we don't have on humonguous one
        sizes[bSet] += sizes[aSet];
    } else {
        arr[bSet] = arr[aSet];
        sizes[aSet] += sizes[bSet];
    }
}

void kruskal (ll x, ll y) {
    int u, v;
    for (int i = 0; i < m; i++) {
        // Select edges one by one in increasing order
        u = p[i].second.first - 1;
        v = p[i].second.second - 1;
        
        // Check if the selected edge is formulating a cycle
        if (findParent(u) != findParent(v) && p[i].first.first >= x && p[i].first.second <= y) {
            vis++;
            Union(u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> d >> t;
        p[i] = make_pair(make_pair(d, t), make_pair(a, b));
    }
    for (int i = 0; i < q; ++i) {
        initialize(n);
        cin >> x >> y;
        kruskal(x, y);
        vis == n ? cout << "YES\n" : cout << "NO\n";
        vis = 1;
    }
    return 0;
}