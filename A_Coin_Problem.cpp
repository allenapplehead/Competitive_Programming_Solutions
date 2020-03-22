#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;

int N, V, l, c, coins[2001], dp[2][10001], ctr = 0, g; // space saving
vector<iiii> queries; // {{c, l}, {i, ans}}

bool sort1(const iiii &a, const iiii &b) {
    return (a.first.second < b.first.second);
}

bool sort2(const iiii &a, const iiii &b) {
    return (a.second.first < b.second.first);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i];    // one indexed
    }
    // take in input first, from there, calculate everything strategically
    for (int i = 0; i < V; i++) {
        cin >> c >> l;
        queries.push_back(make_pair(make_pair(c, l), make_pair(i, 0)));
    }
    for (int i = 1; i < 10001; i++) {
        dp[0][i] = 1e9;
    }
    int curval, cur = 1, prev = 0;
    // first sort by l value
    sort(queries.begin(), queries.end(), sort1);
    /* for (int i = 0; i < 5; i++) {
        cout << queries[i].first.first << " " << queries[i].first.second << " " << queries[i].second.first << " " << queries[i].second.second << "\n";
    } */

    for (int i = 1; i <= N; i++) {
        for (int rem = 0; rem < coins[i]; rem++) {
            deque<int> d;
            for (int j = 0; j <= (10001 - rem) / coins[i]; j++) {
                curval = coins[i] * j + rem;
                if (dp[prev][curval] != 1e9) {
                    while (!d.empty() && dp[prev][d.back() * coins[i] + rem] + j - d.back() >= dp[prev][curval]) {
                        d.pop_back();
                    }
                    d.push_back(j);
                }
                if (d.empty())
                    dp[cur][curval] = 1e9;
                else
                    dp[cur][curval] = dp[prev][coins[i] * d.front() + rem] + j - d.front();
            }
        }
        if (cur == 1) {
            cur = 0;
            prev = 1;
        } else {
            cur = 1;
            prev = 0;
        }
        ctr = g;
        while (queries[ctr].first.second == i && ctr < V) {
            queries[ctr].second.second = dp[prev][queries[ctr].first.first];
            ctr++;
        }
        g = ctr;
    }
    sort(queries.begin(), queries.end(), sort2);
    /* for (int i = 0; i < 5; i++) {
        cout << queries[i].first.first << " " << queries[i].first.second << " " << queries[i].second.first << " " << queries[i].second.second << "\n";
    } */
    for (int i = 0; i < V; i++) {
        if (queries[i].second.second == 1000000000) {
            cout << "-1" << "\n";
        } else {
            cout << queries[i].second.second << "\n";
        }
    }
    return 0;
}