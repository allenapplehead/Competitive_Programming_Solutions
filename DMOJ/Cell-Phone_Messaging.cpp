#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> presses;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    presses.insert({'a', {1, 1}});
    presses.insert({'d', {1, 2}});
    presses.insert({'g', {1, 3}});
    presses.insert({'j', {1, 4}});
    presses.insert({'m', {1, 5}});
    presses.insert({'p', {1, 6}});
    presses.insert({'t', {1, 7}});
    presses.insert({'w', {1, 8}});
    presses.insert({'b', {2, 1}});
    presses.insert({'e', {2, 2}});
    presses.insert({'h', {2, 3}});
    presses.insert({'k', {2, 4}});
    presses.insert({'n', {2, 5}});
    presses.insert({'q', {2, 6}});
    presses.insert({'u', {2, 7}});
    presses.insert({'x', {2, 8}});
    presses.insert({'c', {3, 1}});
    presses.insert({'f', {3, 2}});
    presses.insert({'i', {3, 3}});
    presses.insert({'l', {3, 4}});
    presses.insert({'o', {3, 5}});
    presses.insert({'r', {3, 6}});
    presses.insert({'v', {3, 7}});
    presses.insert({'y', {3, 8}});
    presses.insert({'s', {4, 6}});
    presses.insert({'z', {4, 8}});

    string text;
    cin >> text;
    while (text != "halt") {
        int time = 0;
        for (int i = 1; i < text.length(); ++i) {
            if (presses.at(text[i]).second == presses.at(text[i - 1]).second) {
                time += 2;
            }
            time += presses.at(text[i]).first;
        }
        cout << time + presses.at(text[0]).first << '\n';
        cin >> text;
    }
    return 0;
}