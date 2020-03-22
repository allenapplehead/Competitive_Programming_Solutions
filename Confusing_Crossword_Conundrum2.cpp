#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> t;
map<char, vector<pair<string, int>>> starting; // what starts with what
map<string, int> who;
map<int, string> what;
vector<vector<int>> AdjList(200010);
int ans[27][200010];

void bfs(char start) {
    // simultaneous BFS
    if (starting[start].size()) {
        queue<pair<int, int>> q;
        for (int i = 0; i < starting[start].size(); i++) {
            q.push(make_pair(starting[start][i].second, starting[start][i].second));
        }
        while (!q.empty()) {
            pair<int, int> vertex = q.front(); q.pop();
            if (ans[(int) start - 65][vertex.first] == 0) {
                // not touched yet
                for (int i = 0; i < AdjList[vertex.first].size(); i++) {
                    q.push(make_pair(AdjList[vertex.first][i], vertex.second));
                }
                ans[(int) start - 65][vertex.first] = vertex.second;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // some init
    for (int i = 65; i < 91; i++) {
        starting.insert(make_pair(static_cast<char>(i), t));
    }
    who.insert(make_pair("-1", 0));
    what.insert(make_pair(0, "-1"));

    int N, M, Q, cnt = 1;
    cin >> N >> M >> Q;

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        who.insert(make_pair(temp, i + 1));
        what.insert(make_pair(i + 1, temp));
        starting[temp[0]].push_back(make_pair(temp, i + 1));
    }

    // vector of which starts with which has to be sorted
    for (int i = 65; i < 91; i++) {
        sort(starting[static_cast<char>(i)].begin(), starting[static_cast<char>(i)].end());
        // enumerate them properly
        /* for (int j = 0; j < starting[static_cast<char>(i)].size(); j++) {
            //starting[static_cast<char>(i)][j].second = cnt;
            who[starting[static_cast<char>(i)][j].first] = cnt;
            what[cnt] = starting[static_cast<char>(i)][j].first;
            cnt++;
        } */
    }

    string u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        AdjList[who[u]].push_back(who[v]);
        AdjList[who[v]].push_back(who[u]);
    }

    // precompute everything
    for (int i = 65; i < 91; i++) {
        bfs(static_cast<char>(i));
    }

    string word;
    char clue;
    for (int i = 0; i < Q; i++) {
        cin >> word >> clue;
        cout << what[ans[(int) clue - 65][who[word]]] << "\n";
    }
    return 0;
}