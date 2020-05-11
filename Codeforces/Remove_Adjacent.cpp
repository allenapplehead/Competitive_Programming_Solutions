#include <bits/stdc++.h>
using namespace std;

// allen, you are a weak, non-perservering little piece of shit
// LOOK AT THE FUCKING INPUT CONSTRAINTS (N <= 100)
// WHAT DOES THIS TELL BITCH!? BrUtE fOrCe!!!!!!!!
// AND ALSO HOW TF DID YOU NOT SEE THAT YOU ALWAYS REMOVE THE LARGEST LEXICOGRAPHICAL CHARACTER FIRST YOU MOFO

int n;
string s;
bool visited[105];

char findPrev(int idx, bool up) {
    // returns the adjacent char
    if (idx == 0 || up) {
        idx++;
        while (idx < n) {
            if (!visited[idx]) {
                return s[idx];
            }
            idx++;
        }
    } else if (idx == n - 1 || !up) {
        idx--;
        while (idx >= 0) {
            if (!visited[idx]) {
                return s[idx];
            }
            idx--;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    int ans = 0;
    for (int letter = 25; letter > 0; --letter) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[j]) {
                    continue;
                } else if (s[j] == (char)('a' + letter)) {
                    if (j == 0 && findPrev(j, true) == (char)('a' + letter - 1)) {
                        visited[j] = true;
                        ans++;
                    } else if (j == n - 1 && findPrev(j, false) == (char)('a' + letter - 1)) {
                        visited[j] = true;
                        ans++;
                    } else if (findPrev(j, true) == (char)('a' + letter - 1) || findPrev(j, false) == (char)('a' + letter - 1)) {
                        visited[j] = true;
                        ans++;
                    }
                } 
            }
        }
    }
    cout << ans << '\n';
    return 0;
}