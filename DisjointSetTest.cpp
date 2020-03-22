#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define ln '\n'
// disjoint sets
int arr[1000000];
int sizes[1000000];

// kruskal's
pair <long long, pair<int, int> > p[1000001]; // one million edges
long long nodes, edges;
vector<int> goodEdges;

// main
int n, m, u, v;
long long ans;

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

long long kruskal (pair<long long, pair<int, int> > p[]) {
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < m; i++) {
        // Select edges one by one in increasing order
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        
        // Check if the selected edge is formulating a cycle
        if (findParent(x) != findParent(y)) {
            minimumCost += cost;
            goodEdges.push_back(cost); // we use weight to identify edges
            /* cout << "smol ree" << ln; */
            Union(x, y);
        }
    }
    return minimumCost;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int disc = 0;
    cin >> n >> m;
    initialize(n);
    for (int i = 1; i < m + 1; i++) {
        cin >> u >> v;
        p[i - 1] = make_pair(i, make_pair(u - 1, v - 1));
    }
    ans = kruskal(p);
    for (int i = 0; i < n; i++) {
        if (arr[i] == i) {
            disc++;
        }
    }
    if (disc > 1) {
        cout << "Disconnected Graph" << ln;
    } else {
        for (int e : goodEdges) {
            cout << e << "\n";
        }
    }
    
    return 0;
}