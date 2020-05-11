#include <bits/stdc++.h>
using namespace std;

string words[6] = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"};

int n, message_length, blank_length, blank_unit, blank_mod;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("out.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 0, total = 0, start = 0; i < 6; i++) {
        total += words[i].size();
        if (i < 5 && total + words[i + 1].size() + i - start < n) continue;
        message_length = 0;
        for (int j = start; j <= i; j++) {
            message_length += words[j].size();
        }
        blank_length = n - message_length;
        
        if (i - start == 0) {
            cout << words[i] << string(blank_length, '.');
        } else {
            blank_unit = blank_length / (i - start);
            blank_mod = blank_length % (i - start);
            for (int j = start; j <= i; j++) {
                cout << words[j];
                if (j != i) {
                    cout << string(blank_unit, '.');
                }
                if (blank_mod > 0) {
                    cout << '.';
                }
                blank_mod--;
            }
        }
        start = i + 1;
        total = 0;
        cout << "\n";
    }
    cout << "\n";
    return 0;
}