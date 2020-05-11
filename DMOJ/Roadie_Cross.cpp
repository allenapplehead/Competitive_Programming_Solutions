#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool grid[105][505];
ll dp[105][505];
ll l, w;

ll pos(ll idx) {
    // find the position
    ll ans = idx % w;
    if (ans < 0) {
        ans += w;
    }
    return ans;
}

ll dfs(ll dist, ll prev, ll level) {
    ll mid = w / 2;
    ll p = prev; // keeping it as a constant
    if (level == 1) {
        return dist;
    }
    int dir;
    if (((l + 1) - level) % 2 == 1) {
        dir = 1;
    } else {
        dir = -1;
    }
    ll ans = 1e9;
    if (dp[prev][level] != 1e9) {
        //cout << "USED" << '\n';
        //return dp[prev][level];
    }
    for (int i = 0; i < w; ++i) {
        //cout << "sniping: " << prev << " " << dist << " " << dir << " " << i << '\n';
        ll next = pos(mid + dist * dir * -1 + i * dir * -1);
        prev = pos(p + i * dir);
        if (grid[level][prev] != true) break;
        if (grid[level][prev] && grid[level - 1][next]) {
            //cout << "ADDING: " << next << " " << prev << " " << level << '\n';
            //q.push(make_pair(make_pair(dist + i + 1, next), level - 1));
            ans = min(ans, dfs(dist + i + 1, next, level - 1));
        }
    }
    dp[prev][level] = ans;
    return ans;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int ROUNDS = 1;
    for (int I = 0; I < ROUNDS; ++I) {
        memset(grid, false, sizeof(grid));
        memset(dp, 0, sizeof(dp));
        cin >> l >> w;
        for (int i = 1; i <= l; ++i) {
            for (int j = 0; j < w; ++j) {
                char c;
                cin >> c;
                if (c == '-') grid[i][j] = true;
            }
        }
        for (int i = 0; i < w; ++i) {
            grid[0][i] = true;
            grid[l + 1][i] = true;
        }
        // a breadth first search from here
        //int dist = 1; int prev = mid; int level = l + 1;
        //int ans = bfs(); 
        int mid = w / 2;
        ll ans = dfs(1, mid, l + 1);
        if (ans == 1e9) {
            cout << "Not Possible" << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}