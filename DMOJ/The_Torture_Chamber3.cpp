#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
ull ans = 0;
vector<ull> primes;
bitset<20000010> bs;
ull n, m;

void sieve(ull upper) {
    bs.set();
    primes.push_back(2);
    for (ull i = 3; i <= upper; i += 2) {
        if (bs[i]) {
            for (ull j = i * i; j <= upper; j += i) {
                bs[j] = false;
            }
            primes.push_back(i);
        }
    }
}

void segmented_sieve() {
    ull limit = ceil(sqrt(m));
    sieve(limit); // compute primes to the square root of m
    ull low = n; ull high = m;
    bs.set();
    ull lomin;
    // spam their multiples to find the rest of the primes
    for (int i = 0; i < primes.size(); ++i) {
        lomin = floor(low / primes[i]) * primes[i]; // find the smallest multiple of a prime that is greater than low
        if (lomin < low) lomin += primes[i];
        for (ull j = lomin; j < high; j += primes[i]) { // left closed right open
            bs[j - low] = false; // this basically leverages the problem constraints that m - n <= 2 * 10^7
        }
        if (primes[i] >= n && primes[i] < m) bs[primes[i] - low] = true;
    }
    for (ull i = (low % 2 ? low : low + 1); i < high; i += 2) {
        if (bs[i - low]) {
            ans++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    segmented_sieve();
    cout << ans << '\n';
    return 0;
}