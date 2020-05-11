#include <bits/stdc++.h>
using namespace std;

// pretty simple problem - just find the largest difference between two R cells
// i made the observation that that is the case because any R cell can be reached by a certain conbination of moves
// however editorial took this further by saying we don't need to jump left at all which is big brain

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int r = count(s.begin(), s.end(), 'R');
        // find the maximum distance between two R's
        int cur = 0;
        int mx = 0;
        while (true) {
            int next = s.find("R", cur) + 1;
            //cout << "CUR: " << cur << " " << "NEXT: " << next << '\n';
            if (next == 0) {
                // we have reached the last R
                mx = max(mx, (int)s.length() + 1 - cur);
                break;
            } else {
                mx = max(mx, next - cur);
                cur = next;
            }
        }
        cout << mx << '\n';
    }
    return 0;
}