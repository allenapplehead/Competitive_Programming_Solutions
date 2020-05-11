//https://codeforces.com/problemset/problem/1326/D2
#include <bits/stdc++.h>
 
using namespace std;
 
const int M = (int)(2e6 + 239);
 
int pref[M], c;
 
// * https://cp-algorithms.com/string/prefix-function.html

// by modifying the prefix function by inverting the last half, you are checking palindromes
// the # is needed because the two half must not overlap onto each other 

// KMP

string solve_palindrome(const string& s) // checking what is the biggest prefix you can have that is a palindrome (PREFIX FUNCTION)
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
    return s.substr(0, c);
}
 
void solve()
{
    string t;
    cin >> t;
    int l = 0;
    while (l < (int)t.size() - l - 1)
    {
        if (t[l] != t[(int)t.size() - l - 1])
            break;
        l++;
    }
    if (l > 0)
        cout << t.substr(0, l); // the prefix
    if ((int)t.size() > 2 * l) // if the original string was not a palindrome itself, we solve for the centre
    {
        string s = t.substr(l, (int)t.size() - 2 * l); // s is a substring of the middle segment
        string a = solve_palindrome(s); // try using the sandwiched string in the middle as a suffix of the beginning
        reverse(s.begin(), s.end());
        string b = solve_palindrome(s); // try using the sandwiched string in the middle as a prefix of the end
        if ((int)a.size() < (int)b.size())
            swap(a, b); // exchanges the values of a and b
        cout << a;
    }
    if (l > 0)
        cout << t.substr((int)t.size() - l, l); // the suffix
    cout << "\n";
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}