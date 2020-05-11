#include <bits/stdc++.h>
using namespace std;

// this implementation really twisted my brain up but at least I got it lmao
// basically iterate through the 10^5 array of special numbers (that are to be discarded)
// and simluate the process

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> ar(m);
    for (int i = 0; i < m; ++i) {
        cin >> ar[i];
    }
    ll discarded = 0;
    // discarded with be subtracted from the current scanning value
    ll ans = 0;
    ll page = 0, next = 0, prev = 0;
    while (discarded < m) {
        page = (ar[discarded] - discarded - 1) / k;
        // check how many special items are on that page
        next = page;
        discarded++;
        
        while (next == page) {
            if (discarded >= m) break;
            next = (ar[discarded] - prev - 1) / k;
            if (next == page)
                discarded++;
        }
        ans++;
        prev = discarded;
        //cout << "DISC: " << discarded << '\n';
    }
    cout << ans << '\n';
    return 0;
}