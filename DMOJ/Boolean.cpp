#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string command;
    int nots = 0;
    while (cin >> command && command[0] != 'T' && command[0] != 'F') {
        nots++;
    }
    if (nots % 2 == 0) {
        cout << command << "\n";
    } else {
        if (command[0] == 'T') {
            command = "False";
        } else {
            command = "True";
        }
        cout << command << "\n";
    }
}