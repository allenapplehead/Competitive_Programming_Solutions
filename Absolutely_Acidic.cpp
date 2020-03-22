#include <bits/stdc++.h>
using namespace std;

int freq[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int maxFreq = 0, secondMaxFreq = 0;
    bool dup = false, dup2 = false;
    for (int i = 0, g; i < n; ++i) {
        cin >> g;
        freq[g]++;
        bool update = false;
        if (freq[g] >= maxFreq) {
            if (freq[g] == maxFreq) {
                dup = true;
            } else {
                dup = false;
                maxFreq = freq[g];
                update = true;
            }
        }
        if (!update && freq[g] >= secondMaxFreq) {
            if (freq[g] == secondMaxFreq) {
                dup2 = true;
            } else {
                dup2 = false;
                secondMaxFreq = freq[g];
            }
        }
    }
    // go from either sides 

    if (dup) {
        int a = -1e9, b = -1e9;
        for (int i = 0; i < 1005; ++i) {
            if (freq[i] == maxFreq) {
                a = i;
                break;
            }
        }
        for (int i = 1004; i >= 0; --i) {
            if (freq[i] == maxFreq) {
                b = i;
                break;
            }
        }
        cout << abs(a - b) << '\n';
    } else if (dup2) {
        int a = -1e9, b = -1e9, ans = 0;
        for (int i = 0; i < 1005; ++i) {
            if (freq[i] == maxFreq) {
                a = i;
                break;
            }
        }
        for (int i = 0; i < 1005; ++i) {
            if (freq[i] == secondMaxFreq)
                ans = max(ans, abs(a - i));
        }
        cout << ans << '\n';
    } else {
        int a = -1e9, b = -1e9;
        for (int i = 0; i < 1005; ++i) {
            if (freq[i] == maxFreq) {
                a = i;
            } else if (freq[i] == secondMaxFreq) {
                b = i;
            }
        }
        cout << abs(a - b) << '\n';
    }
    return 0;
}