#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AdjList(100005);
bool pho[100005];
int diameter = 0, leaf = 1e9, ans = 1e9, phoLeft;
bool visited[100005], visitedcpy[100005];

void findDiameter(int vertex, int dist) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        if (dist > diameter) {
            diameter = dist;
            leaf = vertex;
        }
        for (int i = 0; i < AdjList[vertex].size(); ++i) {
            findDiameter(AdjList[vertex][i], dist + 1);
        }
    }
}

// to prune out the tree
stack<int> pruned;
bool vv[100005];
int legals = 0;

void prune(int start) {
    if (vv[start]) {
        return;
    }
    //if (AdjList[start].size() == 1 && vv[AdjList[start][0]]) return;
    vv[start] = true;
    pruned.push(start);
    if (pho[start]) {
        // relieve the stack
        int ss = pruned.size();
        for (int i = 0; i < ss; ++i) {
            int num = pruned.top();
            visited[num] = false;
            legals++;
            pruned.pop();
        }
        for (int i = 0; i < AdjList[start].size(); ++i) {
            prune(AdjList[start][i]);
        }
    } else {
        for (int i = 0; i < AdjList[start].size(); ++i) {
            prune(AdjList[start][i]);
        }
    }
    if (pruned.size() > 0) pruned.pop();
}

int dist = 0;
bool initial = true;


// void dfs(int vertex, int cumDist) {
//     if (!visitedcpy[vertex]) {
//         visitedcpy[vertex] = true;
//         //cout << "visiting: " << vertex << " with cumDist " << cumDist << '\n';
//         if (!initial) {
//             cumDist++;
//         } else {
//             initial = false;
//         }
//         // junction detection
//         int good = 0;
//         for (int i = 0; i < AdjList[vertex].size(); ++i) {
//             if (!visitedcpy[AdjList[vertex].size()]) {
//                 good++;
//             }
//         }
//         if (good == 0 || good > 1) {
//             // it is a endpoint or junction, add
//             dist += cumDist * 2;
//             //cout << "dist: " << dist << '\n';
//             cumDist = 0;
//         }
//         for (int i = 0; i < AdjList[vertex].size(); ++i) {
//             dfs(AdjList[vertex][i], cumDist);
//         }
//     }
// }



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, p = 1e9;
    cin >> n >> m;
    phoLeft = m; // there are m restaurants left to visit
    for (int g, i = 0; i < m; ++i) {
        cin >> g;
        pho[g] = true;
        p = g;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    // prune out the whole tree with bfs all the bad nodes are "visited"
    memset(visited, true, sizeof(visited));
    prune(p);

    for (int i = 0; i < 100005; ++i) {
        visitedcpy[i] = visited[i];
    }

    // debug
    // for (int i = 0; i < 10; ++i) {
    //     cout << visited[i] << ' ';
    // }
    // cout << endl;

    // find the diameter of the tree
    
    // first use a random node
    //cout << "p: " << p << '\n';
    findDiameter(p, 0); 
    //memset(visited, false, sizeof(visited));
    for (int i = 0; i < 100005; ++i) {
        visited[i] = visitedcpy[i];
    }
    //cout << "leaf: " << leaf << '\n';
    findDiameter(leaf, 0);

    // cout << "diameter: " << diameter << '\n';


    // now, depth first search the whole "tour", then subtract the diameter
    //dfs(p, 0);
    
    cout << 2 * (legals - 1) - diameter << '\n';
    //cout << "diam: " << diameter << '\n';
    return 0;
}