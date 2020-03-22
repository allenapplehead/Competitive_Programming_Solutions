#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dependancies(10);
vector<vector<int>> AdjList(10);
bool visited[8];
bool can[8];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    can[2] = true;
    can[3] = true;
    can[6] = true;
    int a, b;
    // preprocessing
    dependancies[7].push_back(1);
    dependancies[4].push_back(1);
    dependancies[1].push_back(2);
    dependancies[4].push_back(3);
    dependancies[5].push_back(3);
    AdjList[1].push_back(7);
    AdjList[1].push_back(4);
    AdjList[2].push_back(1);
    AdjList[3].push_back(4);
    AdjList[3].push_back(5);
    cin >> a >> b;
    while (a != 0 && b != 0) {
        dependancies[b].push_back(a);
        AdjList[a].push_back(b);
        can[b] = false;
        cin >> a >> b;
    }
    vector<int> ans;
    int counter = 0;
    for (int sentinel = 0; sentinel < 7; sentinel++) {
        for (int i = 1; i <= 7; ++i) {
            if (can[i] && !visited[i]) {
                visited[i] = true;
                can[i] = false;
                ans.push_back(i);
                // add the neighbors if their constraints are met
                for (int j = 0; j < AdjList[i].size(); ++j) {
                    // check
                    bool addable = true;
                    for (int k = 0; k < dependancies[AdjList[i][j]].size(); k++) {
                        if (!visited[dependancies[AdjList[i][j]][k]]) {
                            addable = false;
                            break;
                        }
                    }
                    if (addable) can[AdjList[i][j]] = true;
                }
                break;
            }
        }
    }
    if (ans.size() < 7) cout << "Cannot complete these tasks. Going to bed." << '\n';
    else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}