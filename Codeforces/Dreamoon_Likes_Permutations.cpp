#include <bits/stdc++.h>
using namespace std;

// ok, heres the thing
// you have to notice that there will be AT MOST 2 possibilities:
// one that has the biggest element contained in the first half
// two that has the biggest element contained in the last half
// the exception to this is a case like 1 2 3 4 4 3 2 1, where there are two max elements
// so just run two O(n) scans to check both cases, simple

const int MAXN = 200005;
int p[MAXN];
int ans[MAXN][2];
int ans_cnt;
int used[MAXN];

bool judge(int a[], int n) {
    for (int i = 1; i <= n; ++i) used[i] = 0;
    for (int i = 0; i < n; ++i) {
        used[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) return 0;
    }
    return 1;
}

bool judge(int len1, int n) {
    return judge(p, len1) && judge(p + len1 , n - len1); // cool thing with passing arrays
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans_cnt = 0;
        int n;
        cin >> n;
        int ma = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] > ma) ma = p[i];
        }
        if (judge(n - ma, n)) {
            ans[ans_cnt][0] = n - ma;
            ans[ans_cnt][1] = ma;
            ans_cnt++;
        }
        if (ma * 2 != n && judge(ma, n)) {
            // if it is not something like 1 2 3 4 4 3 2 1
            ans[ans_cnt][0] = ma;
            ans[ans_cnt][1] = n - ma; // note that saying ans[ans_cnt++][1] = n - ma means the same thing as lines 53 and 54
            ans_cnt++;
        }
        
        cout << ans_cnt << '\n';
        for (int i = 0; i < ans_cnt; ++i) {
            cout << ans[i][0] << " " << ans[i][1] << '\n';
        }
    }
}