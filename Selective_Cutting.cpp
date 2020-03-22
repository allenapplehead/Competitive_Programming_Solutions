#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l, r, x, idx, res;
};

bool cmp_mass(Query q1, Query q2) {
    return q1.x > q2.x;
}

bool cmp_idx(Query q1, Query q2) {
    return q1.idx < q2.idx;
}

void update(int x, int v, int N, vector<int> &BIT) {
    for (; x <= N; x += (x & -x)) {
        BIT[x] += v;
    }
}

int query(int x, vector<int> &BIT) {
    int res = 0;
    for (; x; x -= (x & -x)) {
        res += BIT[x];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, Q;
    cin >> N;
    vector<pair<int, int>> mass(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mass[i].first = a;
        mass[i].second = i;
    }
    sort(mass.rbegin(), mass.rend());

    // parse queries
    cin >> Q;
    vector<Query> queryArr(Q);
    for (int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        queryArr[i].idx = i;
        queryArr[i].l = l;
        queryArr[i].r = r;
        queryArr[i].x = x;
    }
    sort(queryArr.begin(), queryArr.end(), cmp_mass);

    // fenwick tree of masses, starting with the heaviest (lowest results), and gradually adding more choices
    vector<int> BIT(N + 1, 0);
    int z = 0;
    for (int i = 0; i < Q; i++) {
        int qVal = queryArr[i].x;
        for (; z < N; z++) {
            if (mass[z].first >= qVal) {
                update(mass[z].second + 1, mass[z].first, N, BIT);
            } else {
                break;
            }
        }
        int rsq_wide = query(queryArr[i].r + 1, BIT);
        int rsq = query(queryArr[i].l, BIT);
        queryArr[i].res = rsq_wide - rsq;
    }

    sort(queryArr.begin(), queryArr.end(), cmp_idx); // sort it back to order they were asked in
    for (int i = 0; i < Q; i++) {
        cout << queryArr[i].res << '\n';
    }
    return 0;
}