#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long low = 1, high = 2000000000, mean;
    string r;
    while (low <= high) {
        mean = (low + high) / 2;
        cout << mean << endl;
        cin >> r;
        if (r == "SINKS") {
            low = mean;
        } else if (r == "FLOATS") {
            high = mean;
        } else {
            break;
        }
    }
    
    return 0;
}