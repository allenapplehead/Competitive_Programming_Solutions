#include <bits/stdc++.h>
using namespace std;
string subtraction(string a, string b)
{
    // a - b
    
    bool carry = false;
    string ans;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        int digit = 0;
        if (carry)
        {
            digit -= 1;
            carry = !carry;
        }
        digit += (a[i] + '0') - (b[i] + '0');
        if (digit < 0)
        {
            carry = true;
            digit = 10 + digit;
        }
        ans.insert(0, to_string(digit));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    while (N--)
    {
        int times = 1;
        bool aminusb = false, bminusa = false;
        string a, b, ans;
        bool carry = false;
        cin >> a >> b;
        if (a[0] == '-' && b[0] == '-')
        {
            a.erase(a.begin());
            b.erase(b.begin());
            times = -1;
        }
        else if (a[0] == '-')
        {
            a.erase(a.begin());
            if (a.length() > b.length())
            {
                times = -1;
                aminusb = true;
            }
            else if (b.length() > a.length())
            {
                bminusa = true;
            }
            else
            {
                if (a == b)
                {
                    cout << 0 << "\n";
                    continue;
                }
                else
                {
                    for (int i = 0; i < a.length(); i++)
                    {
                        if (a[i] > b[i]) {
                            times = -1;
                            aminusb = true;
                            break;
                        } else if (b[i] > a[i]) {
                            bminusa = true;
                            break;
                        }
                    }
                }
            }
        }
        else if (b[0] == '-')
        {
            b.erase(b.begin());
            if (b.length() > a.length())
            {
                times = -1;
                bminusa = true;
            }
            else if (b.length() < a.length())
            {
                aminusb = true;
            }
            else
            {
                if (a == b)
                {
                    cout << 0 << "\n";
                    continue;
                }
                else
                {
                    for (int i = 0; i < a.length(); i++)
                    {
                        if (a[i] > b[i]) {
                            aminusb = true;
                            break;
                        } else if (b[i] > a[i]) {
                            times = -1;
                            bminusa = true;
                            break;
                        }
                    }
                }
            }
        }
        // padding
        if (a.length() > b.length())
        {
            b.insert(0, a.length() - b.length(), '0');
        }
        else if (b.length() > a.length())
        {
            a.insert(0, b.length() - a.length(), '0');
        }

        if (!aminusb && !bminusa)
        {
            for (int i = a.length() - 1; i >= 0; i--)
            {
                int digit = 0;
                if (carry)
                {
                    digit += 1;
                    carry = !carry;
                }
                digit += a[i] + b[i] - '0' - '0';
                if (digit >= 10)
                {
                    carry = true;
                    digit = digit % 10;
                }
                ans.insert(0, to_string(digit));
            }
            if (carry) {
                ans.insert(0, 1, '1');
            }
        }
        else if (aminusb)
        {
            ans = subtraction(a, b);
        }
        else if (bminusa)
        {
            ans = subtraction(b, a);
        }
        else
        {
            cout << "ERROR"
                 << "\n";
        }

        if (ans[0] == '0') {
            ans.erase(ans.begin());
        }
        if (times == 1)
            cout << ans << "\n";
        else
            cout << "-" << ans << "\n";
    }

    return 0;
}