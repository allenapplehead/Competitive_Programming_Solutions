#include <bits/stdc++.h>
using namespace std;

map<char, int> roman;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    roman.insert(make_pair('I', 1));
    roman.insert(make_pair('V', 5));
    roman.insert(make_pair('X', 10));
    roman.insert(make_pair('L', 50));
    roman.insert(make_pair('C', 100));
    roman.insert(make_pair('D', 500));
    roman.insert(make_pair('M', 1000));
    string s;
    cin >> s;
    int tot = 0;
    for (int i = 1; i < s.length(); i += 2) {
        if (i + 2 < s.length() && roman.at(s[i]) < roman.at(s[i + 2])) {
            tot -= roman.at(s[i]) * (s[i - 1] - 48);
        } else {
            tot += roman.at(s[i]) * (s[i - 1] - 48);
        }
    }
    cout << tot << '\n';
    return 0;
}