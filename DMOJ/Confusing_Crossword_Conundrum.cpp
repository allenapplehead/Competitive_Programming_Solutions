#include <bits/stdc++.h>
using namespace std;

map <string, vector<string>> AdjList;
map <char, vector<string>> wordBank;
map <char, map<string, string>> answers;

void bfs(char start) {
    // simultaneous BFS!
    if (wordBank[start].size()) {
        sort(wordBank[start].begin(), wordBank[start].end());
        queue<pair<string, string>> q;
        for (string s : wordBank[start]) {
            q.push(make_pair(s, s));
        }

        while (!q.empty()) {
            pair<string, string> vertex = q.front(); q.pop();
            if (answers[start][vertex.first] == "-1") {
                // not visited yet
                //vertex.second = AdjList[vertex.first][0];
                for (string n : AdjList[vertex.first]) {
                    q.push(make_pair(n, vertex.second));
                }
            }
            // add the answer
            if(answers[start][vertex.first] == "-1") answers[start][vertex.first] = vertex.second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    string temp; vector<string> t; char c;

    for (int i = 65; i < 91; i++) {
        wordBank.insert(make_pair(static_cast<char>(i), t));
    }

    for (int i = 0; i < n; i++) {
        cin >> temp; AdjList.insert(make_pair(temp, t));
        c = temp[0]; wordBank[c].push_back(temp); 
        for (int i = 65; i < 91; i++) answers[static_cast<char>(i)].insert(make_pair(temp, "-1"));
        sort(AdjList[temp].begin(), AdjList[temp].end());
    }
    //sort(AdjList.begin(), AdjList.end());

    string u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        AdjList[u].push_back(v); AdjList[v].push_back(u);
    }

    // main routine (precompute the values)

    for (int i = 65; i < 91; i++) {
        c = static_cast<char>(i);
        bfs(c);
    }

    // answer the queries in O(1)

    string word; char clue;
    for (int i = 0; i < q; i++) {
        cin >> word >> clue;
        cout << answers[clue][word] << "\n";
    }

    /* // prints wordbank
    for (auto e: wordBank) {
        cout << e.first <<  " : ";
        for (auto i : e.second) {
            cout << i << " ";
        }
        cout << "\n";
    } */
    /* // prints adjlist
    for (auto e : AdjList) {
        cout << e.first << " : ";
        for (auto i : e.second) {
            cout << i << " ";
        }
        cout << "\n";
    } */
    return 0;
}