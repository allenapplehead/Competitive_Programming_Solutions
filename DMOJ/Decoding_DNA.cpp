#include <bits/stdc++.h>
using namespace std;

string prometer = "TATAAT";

char com (char c) {
    if (c == 'A') {
        return 'T';
    } else if (c == 'T') {
        return 'A';
    } else if (c == 'G') {
        return 'C';
    } else {
        return 'G';
    }
}

int start(string s) {
    // finds the first occurence of the prometer
    bool found;
    for (int i = 0; i < s.length() - prometer.length(); ++i) {
        if (s[i] == prometer[0]) {
            found = true;
            for (int j = i + 1; j < i + prometer.length(); ++j) {
                //cout << "DEBUG: " << s[j] << " " << prometer[j - i] << '\n';
                if (s[j] != prometer[j - i]) {
                    found = false;
                    break;
                }
            }
        }
        if (found) {
            return i + 11;
        }
    }
    return -1;
}

int end(string s, int idx) {
    // find the ending index, the terminator
    bool found = false;
    for (int i = idx + 1; i <= s.length() - 11; ++i) {
        // try to see if it works
        for (int j = s.length() - 1; j >= i + 6; --j) {
            cout << "DEBUG: " << s[i] << " " << s[j] << " | " << com(s[j]) << '\n';
            if (s[i] == com(s[j])) {
                found = true;
                for (int k = 0; k < 6; ++i) {
                    if (s[i + k] != com(s[j - k])) {
                        found = false;
                        break;
                    }
                }
            }
            if (found) {
                return j - 5;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int STRANDS = 1;
    string prometer = "TATAAT";
    for (int i = 0; i < STRANDS; ++i) {
        string s;
        cin >> s;
        int idx = start(s);
        int edx = end(s, idx);
        cout << idx << " " << edx << '\n';
    }
    return 0;
}