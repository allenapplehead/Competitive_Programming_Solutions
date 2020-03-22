#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, l, r, c, com;

vector<vector<int>> ft (21, vector<int>(300005));

void initialize(int n, int which) {
    ft[which].assign(n + 1, 0);
}

void update(int idx, int val, int which) {
    for (; idx < (int) ft[which].size(); idx += (idx & -idx)) {
        ft[which][idx] += val;
    }
}

int rsq(int b, int which) {
    int ans = 0;
    for (; b; b -= (b & -b)) {
        ans += ft[which][b];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i <= 20; i++) {
        initialize(n, i);
    }
    int curval;
    for (int i = 0; i < n; i++) {
        cin >> curval;
        arr[i] = curval;
        update(i + 1, 1, arr[i]);
    }

    while(m--) {
        cin >> com;
        if (com == 1) {
            cin >> a >> b;
            update(a, -1, arr[a - 1]);
            update(a, 1, b);
            arr[a - 1] = b;
        } else {
            cin >> l >> r >> c;
            int counter = 0;
            for (int i = 20; i >= 0; i--) {
                // range sum query
                counter += rsq(r, i) - rsq(l - 1, i);
                if (counter >= c) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}