#include <bits/stdc++.h>
using namespace std;

vector <int> pfactors;

void pf (int number) {
    int cnt = 2, last;
    while (cnt * cnt <= number) {
        if (number % cnt == 0) {
            number /= cnt;
            pfactors.push_back(cnt);
            //last = pfactors.size();
        } else {
            cnt++;
        }
    }
    pfactors.push_back(number);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, cur;
    cin >> N;
    while (N--) {
        cin >> cur; pf(cur);
        for (int i = 0; i < pfactors.size(); i++) {
            cout << pfactors[i];
            if (i == pfactors.size() - 1) {
                cout << "\n";
            } else {
                cout << " ";
            }
        }
        pfactors.clear();
    }
    return 0;
}