#include <bits/stdc++.h>
using namespace std;

string s;
long long l, k;

long long a[26];
long long sh[26]; // a copy of "a"

long long solve()
{
    long long l = -1;
    long long r = s.length();
    while (l + 1 < r)
    {
        long long m = (l + r) / 2;
        long long s = 0;
        for (int i = 0; i < 26; i++)
        {
            if (sh[i] > m)
            {
                s += sh[i] - m;
            }
        }
        if (s > k)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    long long left = k;
    vector<long long> a2;
    for (int i = 0; i < 26; i++)
    {
        if (sh[i] > r)
        {
            left -= (sh[i] - r);
            sh[i] = r;
        }
        a2.push_back(sh[i]);
    }
    sort(a2.begin(), a2.end(), greater<long long>());
    long long sc = 0;
    for (int i = 0; i < a2.size(); i++)
    {
        if (left && a2[i] > 0)
        {
            left--;
            sc += (a2[i] - 1) * (a2[i] - 1);
        }
        else
        {
            sc += a2[i] * a2[i];
        }
    }
    return sc;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*     freopen("inn.txt", "r", stdin);
    freopen("outt.txt", "w", stdout); */
    cin >> s >> l >> k;
    if (l + k >= s.length())
    {
        cout << 0 << '\n';
        return 0;
    }
    // parse the input
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 97]++;
        sh[s[i] - 97]++;
    }
    long long ans = 1e9;
    if (l == 0)
    {
        ans = solve();
    }
    else
    {
        // maintain a sliding window
        for (int i = 0; i < l; i++) {
            a[s[i] - 97]--;
            sh[s[i] - 97]--;
        }
        ans = solve();
        for (int i = 0; i < 26; i++) sh[i] = a[i];

        //cout << ans << '\n';
        for (int j = l; j < s.length(); j++) {
            sh[s[j - l] - 97] += 1;
            sh[s[j] - 97] -= 1;
            a[s[j - l] - 97] += 1;
            a[s[j] - 97] -= 1;                   
            for (int i = 0; i < 26; i++) sh[i] = a[i];
            ans = min(ans, solve());
        }
    }
    cout << ans << '\n';
    return 0;
}