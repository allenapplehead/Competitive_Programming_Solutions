#include <bits/stdc++.h>
using namespace std;

long long N;
char sets, idk;

map<char, set<char>> s;     // adjacency list :s
set<char> ss;               // just an empty set
bitset<26> visited;         // by ascii value - 65

void dfs(char start) {
    cout << start << "\n";
    if (!visited[start]) {
        visited[start] = 1;
        for (auto e : s[start]) {
            cout << "\tIn set: " << start << " : " << e << "\n";
            if (isupper(e)) {
                // it is a set, thus we keep recursing
                if (!visited[e]) dfs(e);
                s[start].erase(e);
                s[start].insert(s[e].begin(), s[e].end());
            } else {
                s[start].insert(e);
            }
        }
    }
    
}
int main() {
    scanf("%lld", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c contains %c", &sets, &idk);
        if (s.find(sets) == s.end()) {
            s.insert(make_pair(sets, ss));
        }
        if (isupper(idk)) {
            if (s.find(idk) == s.end()) {
                s.insert(make_pair(idk, ss));
            }
        }
        s[sets].insert(idk);
    }
    // run dfs routine
    dfs(sets); // root it arbitrarily

    int cnt = 0;
    for (auto& kv : s) {
        cnt = 0;
        printf("%c = {", kv.first);
        for (auto val : kv.second) {
            cnt++;
            printf("%c", val);
            if (cnt == kv.second.size()) {
                printf("}\n");
            } else {
                printf(",");
            }
        }
        if (cnt == 0) printf("}\n");
    }
    return 0;
}