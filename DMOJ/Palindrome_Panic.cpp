#include <bits/stdc++.h>
using namespace std;

int pref[2000005], c;
string s;

int solve_palindrome() // checking what is the biggest prefix you can have that is a palindrome (PREFIX FUNCTION)
{
    string a = s;
    reverse(a.begin(), a.end());
    a = s + "#" + a;
    //cout << "Solving: " << a << '\n';
    c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int TESTS = 10;
    for (int i = 0; i < TESTS; ++i) {
        cin >> s;
        int ans = 1e9;
        int len = s.length();
        memset(pref, 0, sizeof(pref));
        ans = min(ans, len - solve_palindrome());
        reverse(s.begin(), s.end());
        ans = min(ans, len - solve_palindrome());
        cout << ans << '\n';
    }
    return 0;
}