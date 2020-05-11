#include <bits/stdc++.h>
using namespace std;

// note

// simulate the whole process and then choose who's left

bool princes[100005];
int unmarried = -1, who = -1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        // resets
        memset(princes, false, sizeof(princes));
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            bool married = false;
            for (int g, j = 0; j < num; ++j) {
                cin >> g; g--;
                if (princes[g] == false && married == false) {
                    princes[g] = true;
                    married = true;
                }
            }
            if (!married) {
                unmarried = i + 1;
            }
        }
        // check if we can improve the solution
        bool imp = false;
        for (int i = 0; i < n; ++i) {
            if (princes[i] == false) {
                who = i + 1;
                imp = true;
                break;
            }
        }
        // print the answer
        if (imp) {
            cout << "IMPROVE" << '\n';
            cout << unmarried << " " << who << '\n';
        } else {
            cout << "OPTIMAL" << '\n';
        }
    }
    return 0;
}