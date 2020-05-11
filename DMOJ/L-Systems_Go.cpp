#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T = 10;
    while (T--) {
        int r, t;
        string a;
        cin >> r >> t >> a;
        vector<pair<char, string>> rules;
        for (int i = 0; i < r; ++i) {
            char c;
            string s;
            cin >> c >> s;
            rules.push_back(make_pair(c, s));
        }
        long long freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i = 0; i < a.length(); ++i) {
            freq[a[i] - 'A']++;
        }
        long long new_freq[26];
        char start = a[0];
        char end = a[a.length() - 1];
        long long sigma = 0;
        bool bchange = false, echange = false;
        for (int i = 0; i < t; ++i) {
            bchange = false;
            echange = false;
            memset(new_freq, 0, sizeof(new_freq));
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < rules[j].second.length(); ++k) {
                    new_freq[rules[j].second[k] - 'A'] += freq[rules[j].first - 'A'];
                }
                if (rules[j].first == start && !bchange) {
                    start = rules[j].second[0];
                    bchange = true;
                }
                if (rules[j].first == end && !echange) {
                    end = rules[j].second[rules[j].second.length() - 1];
                    echange = true;
                }
            }
            for (int j = 0; j < 26; ++j) {
                freq[j] = new_freq[j];
            }
        }
        for (int i = 0; i < 26; ++i) {
            sigma += freq[i];
        }
        cout << start << end << " " << sigma << '\n';
    }
    return 0;
}