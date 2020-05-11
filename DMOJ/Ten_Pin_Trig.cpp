#include <bits/stdc++.h>
using namespace std;

long double ed (long double x, long double y, long double x1, long double y1) {
    return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 10;
    int points = 5;
    while (T--) {
        long double x, y;
        int expx, expy;
        long double s;
        int exps;
        int n;
        cin >> x >> expx >> y >> expy >> s >> exps >> n;
        // generate all the bowling pin's locations based off of the first one
        vector<pair<long double, long double>> tri(11);
        x *= pow(10, expx);
        y *= pow(10, expy);
        tri[1] = make_pair(x, y);
        s *= pow(10, exps);
        s /= 3;
        long double ya = (s / 2.0) * sqrt(3.0);
        tri[2] = make_pair(x - s / 2.0, y + ya);
        tri[3] = make_pair(x + s / 2.0, y + ya);
        tri[4] = make_pair(tri[2].first - s / 2.0, tri[2].second + ya);
        tri[5] = make_pair(tri[2].first + s / 2.0, tri[2].second + ya);
        tri[6] = make_pair(tri[3].first + s / 2.0, tri[3].second + ya);
        tri[7] = make_pair(tri[4].first - s / 2.0, tri[4].second + ya);
        tri[8] = make_pair(tri[4].first + s / 2.0, tri[4].second + ya);
        tri[9] = make_pair(tri[5].first + s / 2.0, tri[5].second + ya);
        tri[10] = make_pair(tri[6].first + s / 2.0, tri[6].second + ya);
        for (int I = 0; I < points; ++I) {
            long double posx, posy;
            int ex, ey;
            cin >> posx >> ex >> posy >> ey;
            posx *= pow(10, ex);
            posy *= pow(10, ey);
            // brute force distance to all points
            int ans = -1e9;
            long double mi = 1e9;
            for (int i = 1; i <= 10; ++i) {
                if (ed(posx, posy, tri[i].first, tri[i].second) < mi) {
                    mi = ed(posx, posy, tri[i].first, tri[i].second);
                    ans = i;
                }
            }
            cout << ans;
            if (I == points - 1) {
                cout << '\n';
            } else {
                cout << ' ';
            }
        }
    }
    return 0;
}