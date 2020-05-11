#include <bits/stdc++.h>
using namespace std;

int N;
int config[9], hashs;
bitset<1000001> visited;

int h (int hashs[], int s) {
    int ans = 0;
    double f;
    cout << s << "\n";
    for (int i = 0; i < s; i++) {
        cout << "PARSING: " << hashs[i] << " " << pow(10, s - i - 1) << "\n";
        f = pow(10, (s - i - 1));
        ans += hashs[i] * f;
        cout << ans << " " << hashs[i] * pow(10, s - i - 1) << "\n";
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> N && N != 0) {
        visited.set(); // true means unvisited
        vector<int> coins;
        for (int temp, i = 0; i < N; i++) {
            cin >> temp;
            coins.push_back(temp);
        }
        // parse the input into our format
        for (int i = 1; i <= N; i++) {
            config[coins[i - 1] - 1] = i;
        }
        hashs = h(config, N);
        for (int i = 0; i < N; i++) {
            cout << config[i] << " ";
        }
        cout << "\n";
        cout << hashs << "\n";

    }
    return 0;
}