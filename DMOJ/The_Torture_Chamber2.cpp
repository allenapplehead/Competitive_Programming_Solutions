#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bitset <25454> bs;
    bs[9432] = 1;
    long long limit = ceil(sqrt(bs.size()));
    long long prev = 0;
    while (limit <= 25454) {
        for (long long i = prev; i < limit; i++) {
            cout << bs[i] << endl;
        }
        prev = limit;
        limit += limit;
    }
    return 0;
}