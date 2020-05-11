#include <bits/stdc++.h>
using namespace std;

// editorial is good

vector<vector<int>> AdjList(300005);
bool even = true; // to see if all distances between all leaf nodes are even
int e = 0;
int l = 0;
int m = 0;
int parity = -1;
bitset<300005> leaves;
bitset<300005> vis;

void findLeaves(int start, int dist, bool secondrun) {
    if (!vis[start]) {
        vis[start] = true;
        // check if this is a leafy boi
        if (!secondrun && AdjList[start].size() == 1) {
            leaves[start] = true;
            l++;
            // check parity of distance
            if (parity == -1) {
                parity = dist % 2;
            } else if (parity != dist % 2) {
                even = false;
            }
        }
        bool add = false;
        for (int i = 0; i < AdjList[start].size(); ++i) {
            // if a neighbor is leaf
            if (secondrun && leaves[AdjList[start][i]] == true) {
                add = true;
            }
            findLeaves(AdjList[start][i], dist + 1, secondrun);
        }
        if (add) m++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int p;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
        p = v;
    }
    // basically just split into 2 cases: the MIN and the MAX
    findLeaves(p, 0, false);
    vis.reset();
    findLeaves(p, 0, true);
    e = n - 1;

    // MIN (either you can make it 1 if all distances from edge to edge are even or it is provable that otherwise its 3)
    int mi = 1e9;
    if (!even) {
        mi = 3;
    } else {
        mi = 1;
    }

    // MAX (edges - leaves + non-leaves that have leaf as neighbor)
    int ma = e - l + m;

    // PRINT ANS
    cout << mi << ' ' << ma << '\n';

    return 0;
}