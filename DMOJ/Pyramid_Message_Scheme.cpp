#include <bits/stdc++.h>
using namespace std;

int AdjMat[105][105];
map<string, int> dict;

int dfs(int vertex) {
    int junction = 0;
    // base case
    bool able = false;
    for (int i = 0; i < 105; ++i) {
        if (AdjMat[vertex][i]) {
            able = true;
            break;
        }
    }
    if (!able) {
        return 1;
    } else {
        for (int i = 0; i < 105; ++i) {
            if (AdjMat[vertex][i]) {
                junction = max(junction, dfs(AdjMat[vertex][i]));
            }
        }
    }
    if (junction == 1) {
        return 2;
    } else {
        return junction + 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        dict.clear();
        memset(AdjMat, 0, sizeof(AdjMat));
        vector<string> names;
        int n, current = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if (dict.find(s) == dict.end()) {
                dict.insert(make_pair(s, current));
                current++;
            }
            names.push_back(s);
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (AdjMat[dict.at(names[names.size() - 1])][dict.at(names[i])] == false && AdjMat[dict.at(names[names.size() - 1])][dict.at(names[i])] == false)
                    AdjMat[dict.at(names[names.size() - 1])][dict.at(names[i])] = true;
            } else {
                if (AdjMat[dict.at(names[i - 1])][dict.at(names[i])] == false && AdjMat[dict.at(names[i - 1])][dict.at(names[i])] == false) {
                    AdjMat[dict.at(names[names.size() - 1])][dict.at(names[i])] = true;
                }
            }
        }
        cout << n * 10 - dfs(dict.at(names[names.size() - 1])) * 10 << '\n';
    }
    return 0;
}