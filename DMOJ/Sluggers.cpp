#include <bits/stdc++.h>
using namespace std;

string format(long double num) {
    //cout << "rounding: " << num << '\n';
    num = round(num * 1000.0) / 1000.0;
    string s = to_string(num);
    return s.substr(1, 4);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("out.txt", "w", stdout);
    string s;
    getline(cin, s);
    long double gp, ab, r, ht, h2, h3, h4, h1;
    long double t1 = 0, t2 = 0, t3 = 0;
    //vector<pair<string, pair<double, double>>> names;
    cout << s << '\n';
    cout << "====================" << '\n';
    for (int i = 0; i < 10; ++i) {
        cin >> s;
        cin >> gp >> ab >> r >> ht >> h2 >> h3 >> h4;
        h1 = ht - h2 - h3 - h4;
        cout << s << ": " << format(ht / ab) << " " << format((h1 + 2 * h2 + 3 * h3 + 4 * h4) / ab) << '\n';
        //names.push_back(make_pair(s, make_pair(ht / ab, (h1 + 2 * h2 + 3 * h3 + 4 * h4) / ab)));
        t1 += ht; t2 += (h1 + 2 * h2 + 3 * h3 + 4 * h4);
        t3 += ab;
    }
    cout << "====================" << '\n';
    cout << "Big 10 Av: " << format(t1/t3) << " " << format(t2/t3);
    return 0;
}