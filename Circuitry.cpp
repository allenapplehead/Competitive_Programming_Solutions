#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> order;                                   // the order in which we print edges
pair<int, pair<int, int>> p[500 * 500 / 2];               // edge list for kruskals
int states[501][501];                                           // our answers

queue<pair<int, int>> q;                 // edges belonging to our initial mst
pair<int, int> temp;

int N, M, u, v, w;  // input
int A[501];         // disjoint set parents
int sizes[501];     // disjoint set sizes

// disjoint set
void initialize(int N) {
    for (int i = 0; i < N; i++) {
        A[i] = i;
        sizes[i] = 1;
    }
}

int findParent(int i) {
    while (A[i] != i) {
        A[i] = A[A[i]]; // path compression
        i = A[i];
    }
    return i;
}

void Union(int a, int b) {
    int aSet = findParent(a);
    int bSet = findParent(b);
    if (sizes[aSet] > sizes[bSet]) {
        A[aSet] = A[bSet];
        sizes[bSet] += sizes[aSet];
    } else {
        A[bSet] = A[aSet];
        sizes[aSet] += sizes[bSet];
    }
}

// kruskal's algo routine
int kruskal(pair<int, pair<int, int>> p[], int u, int v) {
    int x, y;
    int cost;
    int minCost = 0;
    for (int i = 0; i < M; i++) {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if (findParent(x) != findParent(y) && !(x == u && y == v)) {
            minCost += cost;
            // update the value in AdjList

            if (u == 1e9 && v == 1e9) { // dont do triple equalities a == b == c
                q.push({x, y});
                states[x][y] = 2; // useful
            }
                
            else if (states[x][y] == 0) {
                temp.first = x;
                temp.second = y;
            }
            Union(x, y);
        }
    }
    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        order.push_back({u - 1, v - 1});
        p[i] = {w, {u - 1, v - 1}};
    }
    sort(p, p + M);
    initialize(N);
    int minimumCost = kruskal(p, 1e9, 1e9);
    int shadow;

    while (q.size()) {
        initialize(N);
        pair<int, int> v = q.front(); q.pop();
        shadow = kruskal(p, v.first, v.second);
        if (shadow == minimumCost) {
            states[temp.first][temp.second] = 1;
            states[v.first][v.second] = 1;
            
        }
    }

    for (auto pr : order) {
        if (states[pr.first][pr.second] == 2) {
            cout << "useful" << "\n";
        } else if (states[pr.first][pr.second] == 1) {
            cout << "so so" << "\n";
        } else {
            cout << "not useful" << "\n";
        }
    }
    return 0;
}