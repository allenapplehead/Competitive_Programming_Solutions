#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int UPTO = 10000000;

bool primes[UPTO + 1];
int a = -1e9, b = -1e9, c = -1e9;

void solve2(int n) {
    ll i = n / 2;
    for (i; i >= 3; --i) {
        if (primes[i] && primes[n - i]) {
            a = i;
            b = n - i;
            break;
        }
    }
}

void e() {
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for (ll i = 2; i * i <= UPTO; ++i) {
        if (primes[i]) {
            for (ll j = i * i; j <= UPTO; j += i) {
                primes[j] = false;
            }
        }
    }
    primes[2] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int TESTS = 5;
    e();
    for (int I = 0; I < TESTS; ++I) {
        int n;
        cin >> n;
        ll i = 0;
        if (primes[n]) {
            cout << n << " = " << n << '\n';
            continue;
        }
        if (n % 2 == 0) {
            solve2(n);
            cout << n << " = " << a << " + " << b << '\n';
        } else {
            i = n / 3;
            vector<ll> ar(3);
            for (i; i >= 3; --i) {
                if (primes[i]) {
                    solve2(n - i);
                    if (i + a + b == n && a >= i) {
                        ar[0] = i;
                        ar[1] = a;
                        ar[2] = b;
                        break;
                    }
                }
            }
            sort(ar.begin(), ar.end());
            cout << n << " = " << ar[0] << " + " << ar[1] << " + " << ar[2] << '\n';
        }
    }
    return 0;
}