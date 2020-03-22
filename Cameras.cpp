#include <bits/stdc++.h>
using namespace std;

long long n, k, r, camera, res = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k >> r;
    vector<pair<int, bool>> a(n);
    for (int i = 1; i <= n; i++) {
        a[i - 1] = make_pair(i, false);
    }
    for (int i = 0; i < k; i++) {
        cin >> camera;
        a[camera - 1].second = true;
    }

    // main routine
    int cnt = 0, lste = -1, slste = 0;
    for (int i = r - 1; i < n; i++) {
        if (i == r - 1) {
            for (int j = i - r + 1; j <= i; j++) {
                if (a[j].second) {
                    cnt++;
                } else {
                    if (lste!=-1) {
                        slste = lste;
                    }
                    lste = j;
                }
            }
        } else {
            if (a[i - r].second) {
                cnt--;
            }
            if (a[i].second) {
                cnt++;
            } else {
                if (lste!=-1) {
                    slste = lste;
                }
                lste = i;
            }
        }
        if (cnt == 1) {
            a[lste].second = true;
            cnt++;
            res++;
        } else if (cnt == 0) {
            a[lste].second = true;
            a[slste].second = true;
            cnt += 2;
            res += 2;
        }
    }
    cout << res << "\n";
    return 0;
}