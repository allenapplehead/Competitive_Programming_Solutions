#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 1;

map<int, long double> compress;
long double ft[100005];

void update(int val) {
    for (; val < 100005; val += val & -val) {
        ft[val + OFFSET]++;
    } 
}

long long rsq(int a) {
    long long ans = 0.0;
    for (; a; a -= (a & -a)) {
        ans += ft[a + OFFSET];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<long double> ar(n);
    vector<long double> ar2(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        ar2[i] = ar[i];
    }
    // compress the array
    sort(ar2.begin(), ar2.end());

    for (int i = 1; i <= n; ++i) {
        compress.insert(make_pair(ar2[i - 1], i));
    }

    // update and find position along the way
    long double avg = 0;
    for (int i = 0; i < n; ++i) {
        avg += (i + 1 - rsq(compress.at(ar[i])));
        update(compress.at(ar[i]));
    }
    double en = (double) n;
    cout << fixed << setprecision(2) << (double)avg / en << '\n';
    return 0;
}