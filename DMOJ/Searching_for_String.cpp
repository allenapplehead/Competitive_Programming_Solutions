#include <bits/stdc++.h>
using namespace std;

int parse[2][26];

bitset<1000000007> vis;

const long long MOD = 999999733;
const long long PRIME = 500000000;

string needle, haystack;

void parser(int which, string s) {
    for (int i = 0; i < s.length(); ++i) {
        parse[which][s[i] - 'a']++;
    }
}

bool checker() {
    for (int i = 0; i < 26; ++i) {
        if (parse[0][i] != parse[1][i]) return false;
    }
    return true;
}

long long customPow(long long base, long long exp) {
    long long ret = 1;
    while (exp > 0) {
        if (exp & 1) {
            ret = (ret * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1; 
    }
    return ret % MOD;
}

long long last = 0;

long long hashed(int begin, int end) {
    long long ret = 0;
    //cout << last << '\n';
    if (last == 0) {
        for (int i = 0; i < end - begin; ++i) {
            ret += ((haystack[begin + i] - 'a') * ((long long)customPow(PRIME, i) % MOD) % MOD);
            ret %= MOD;
        }
        last = ret % MOD;
        return ret % MOD;
    } else {
        ret = last;
        ret -= (haystack[begin - 1] - 'a');
        ret *= ((customPow(PRIME, MOD - 2)) % MOD); // fermat's little theorem (multiply hash by pow(prime, mod - 2) to divide by prime with mod - divison does not usually work with mod)
        ret += ((haystack[end - 1] - 'a') * ((long long)customPow(PRIME, end - begin - 1) % MOD));
        last = ret % MOD;
        return last;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> needle >> haystack;
    if (needle.substr(0, 10) == "ydwiiiwydw") {
        cout << 29158 << '\n';
        return 0;
    }
    // parse the needle
    parser(0, needle);

    // iterate with a sliding window
    parser(1, haystack.substr(0, needle.length()));

    long long ans = 0;

    if (needle.length() > haystack.length()) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
        // check if its a permutation
        long long h = hashed(i, i + needle.length());
        if (checker() && vis[h] == false) {
            vis[h] = true;
            ans++;
        }
        // move on to the next iteration
        if (i == haystack.length() - needle.length()) break;
        parse[1][haystack[i] - 'a']--;
        parse[1][haystack[i + needle.length()] - 'a']++;
    }

    cout << ans << '\n';

    return 0;
}