#include <bits/stdc++.h>
using namespace std;

long long w, d, v;
vector<int> working;
set<long long> possible;
bool vis[10][5000010];
void f (long long cur, int steps) {
    // base cases
    if (vis[steps][cur]) {
        return;
    }
    vis[steps][cur] = true;
    if (steps >= w) {
        // we found one
        possible.insert(cur);
        return;
    }

    // main routine
    int res;
    for (int i = 0; i < (int)working.size(); i++) {
        // complete search every workable digit
        for (int j = 0; j < 2; j++) {
            j == 0 ? f(cur + working[i], steps + 1) : f(cur * working[i], steps + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> w >> d;
    for (int temp, i = 0; i < d; i++) {
        cin >> temp;
        working.push_back(temp);
    }
    
    int ans; bool found;
    for (long long i : working) {
        f(i, 0);
    }

    cin >> v;
    
    for (long long temp, i = 0; i < v; i++) {
        found = false;
        cin >> temp;
        if (possible.find(temp) != possible.end()) {
            found = true;
        }
        if (found) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;
}