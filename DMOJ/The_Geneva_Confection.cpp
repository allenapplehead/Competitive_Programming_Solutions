#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        stack<int> s;
        vector<int> so;
        reverse(ar.begin(), ar.end());
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            //cout << i << " " << ar[i] << '\n';
            if (ar[i] != cur) {
                //cout << "pushing to stack " << ar[i] << '\n';
                s.push(ar[i]);
            } else {
                so.push_back(cur);
                ++cur;
                // check the stack
                while (!s.empty() && s.top() == cur) {
                    so.push_back(s.top());
                    s.pop();
                    ++cur;
                }
            }
        }

        // debug
        //cout << "fdsf" << '\n';
        // for (int i = 0; i < so.size(); ++i) {
        //     cout << so[i] << " ";
        // }
        //cout << "fjdlkj" << endl;
        //cout << "stack size: " << s.size() << '\n';
        int si = s.size();
        for (int i = 0; i < si; ++i) {
            //cout << s.top() << '\n';
            int num = s.top();
            s.pop();
            so.push_back(num);
        }
        // debug
        // for (int i = 0; i < n; ++i) {
        //     cout << so[i] << ' ';
        // }
        string ans = "Y";
        for (int i = 1; i < so.size(); ++i) {
            if (so[i] < so[i - 1]) {
                ans = "N";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}