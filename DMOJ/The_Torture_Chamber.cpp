#include <bits/stdc++.h>
using namespace std;
vector<long long> primes;
bitset <20000010> bs; // keeps track of primes
long long ans = 0;

void se(long long upto) {
    bs.set(); // set all to true
    for (long long i = 2; i * i < upto; i++) {
        if (bs[i]) { 
            for (long long j = i * i; j <= upto; j += i) {
                // falsify all multiples
                bs[j] = false;
            }
            primes.push_back(i);
        }
        
    }
}

bool isprime(long long num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num <= primes[primes.size() - 1])
    {
        for (long long i = 0; i < primes.size(); i++)
        {
            if (num == primes[i])
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        for (long long i = 0; i < primes.size(); i++)
        {
            if (num % primes[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void seg(long long lower, long long higher)
{
    // segmented sieve
    // this is in left closed, right open [, )

    // square root decomposition:
    long long cur = lower;
    long long upto = cur + sqrt(higher - lower);
    bool left = true;
    while (left)
    {
        if (cur == upto)
        {
            upto += upto;
            if (upto >= higher)
            {
                upto = higher;
                left = false;
            }
        }
        for (long long i = cur; i < upto; i++)
        {
            if (isprime(cur) == true)
            {
                ans++;
            }
            cur++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long lower, higher;
    cin >> lower >> higher;
    se(higher);
    seg(lower, higher);
    cout << ans << endl;
    return 0;
}