#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    for (int i : arr) {
        cout << i << "\n";
    }
    return 0;
}