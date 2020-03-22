#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int width = 0, height = 0;
        int mw = 0, mh = 0, miw = 0, mih = 0, ban1, ban2;
        // split into WS string and AD string
        for (int i = 0; i < s.length(); ++i) {
            // WS
            vector<int> a(200005); a[0] = 0;
            if (s[i] == 'W') {
                a[i + 1] = a[i] + 1;
            } else if (s[i] == 'S') {
                a[i + 1] = a[i] - 1;
            }
        }
        for (int i = 0; i < s.length(); ++i) {
            // AD
            vector<int> a(200005); a[0] = 0;
            if (s[i] == 'A') {
                a[i + 1] = a[i] - 1;
            } else if (s[i] == 'D') {
                a[i + 1] = a[i] - 1;
            }
        }
    return 0;
}