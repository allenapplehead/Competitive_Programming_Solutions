#include <bits/stdc++.h>
using namespace std;

// games are 1-2 1-3 1-4 2-3 2-4 3-4
pair<int, int> poss[6] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
int ans = 0, tgt;

void solve(int gp, int games[]) {
    if (gp == 6) {
        int scores[4];
        memset(scores, 0, sizeof(scores));
        for (int i = 0; i < 6; ++i) {
            if (games[i] == 3) {
                scores[poss[i].first] += 3;
            } else if (games[i] == 2) {
                scores[poss[i].first] += 1;
                scores[poss[i].second] += 1;
            } else {
                scores[poss[i].second] += 3;
            }
        }
        int maxScore = -1e9, winner = -1e9;
        for (int i = 0; i < 4; ++i) {
            if (scores[i] > maxScore) {
                maxScore = scores[i];
                winner = i;
            } else if (scores[i] == maxScore) {
                winner = -1e9;
            }
        }
        if (winner == tgt) ++ans;
    } else {
        // find the next unplayed game
        for (int i = 0; i < 6; ++i) {
            if (games[i] == 0) {
                // simulate all three cases
                games[i] = 3;
                solve(gp + 1, games);
                games[i] = 2;
                solve(gp + 1, games);
                games[i] = 1;
                solve(gp + 1, games);
                games[i] = 0;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, g, a, b, sa, sb, games[6];
    memset(games, 0, sizeof(games));
    cin >> t >> g;
    tgt = t - 1;
    // win - 3 tie - 2 loss - 1 unplayed - 0
    for (int i = 0; i < g; ++i) {
        cin >> a >> b >> sa >> sb;
        --a; --b;
        for (int j = 0; j < 6; ++j) {
            if (poss[j].first == a && poss[j].second == b) {
                // decide on winning condition
                if (sa > sb) {
                    games[j] = 3;
                } else if (sb > sa) {
                    games[j] = 1;
                } else {
                    games[j] = 2;
                }
            }
        }
    }
    solve(g, games);
    cout << ans << '\n';
    return 0;
}