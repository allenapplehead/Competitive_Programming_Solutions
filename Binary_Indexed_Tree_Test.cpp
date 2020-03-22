#include <bits/stdc++.h>
using namespace std;


vector<long long> ftr;
vector<long long> ftc;
long long rsq_ftr(long long a, long long b) {
    long long sumb = 0, suma = 0;
    for (; b; b -= (b & -b)) {
        sumb += ftr[b];
    }
    if (a == 1) {
        suma = 0;
    } else {
        a--;
        for (; a; a -= (a & -a)) {
            suma += ftr[a];
        }
    }
    return sumb - suma;
}

long long rsq_ftc(long long a, long long b) {
    long long sumb = 0, suma = 0;
    for (; b; b -= (b & -b)) {
        sumb += ftc[b];
    }
    if (a == 1) suma = 0;
    else {
        a--;
        for (; a; a -= (a & -a)) {
            suma += ftc[a];
        }
    }
    return sumb - suma;
}

void update_ftr(long long k, long long v) {
    for (; k < (long long)ftr.size(); k += (k & (-k))) ftr[k] += v;
}

void update_ftc(long long k, long long v) {
    for (; k < (long long)ftc.size(); k += (k & (-k))) ftc[k] += v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, m, x, va, l, r, temp, dif, last;
    char command;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    // prepare 2 fenwick trees, one for rmq, once for cumulative frequency tables
    ftr.assign(n + 1, 0);
    ftc.assign(100002, 0);
    for (int i = 1; i <= n; i++) {
        update_ftr(i, a[i - 1]);
        update_ftc(a[i - 1], 1);
    }

    while (m--) {
        cin >> command;
        if (command == 'C') {
            cin >> x >> va;
            dif = va - a[x - 1];
            last = a[x - 1];
            a[x - 1] = va;
            update_ftc(last, -1);
            update_ftc(va, 1);
            update_ftr(x, dif);
        } else if (command == 'S') {
            cin >> l >> r;
            cout << rsq_ftr(l, r) << '\n';
        } else {
            cin >> va;
            cout << rsq_ftc(1, va) << '\n';
        }
    }
    return 0;
}