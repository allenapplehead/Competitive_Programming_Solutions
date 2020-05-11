#include <bits/stdc++.h>
using namespace std;

#define INF 9223372036854775807;
#define MOD 1000000007;
long long ans1 = 0, ans2 = 0;
long long N, arr1[100000], arr2[100000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }
    sort(arr1, arr1 + N);
    sort(arr2, arr2 + N);
    // N will now represent the length of array
    for (int i = 0; i < N - 1; i++) {
        if (arr1[i] == 1 || arr1[i + 1] == 1) {
            arr1[i + 1] = (arr1[i] * arr1[i + 1]) % MOD;
        } else {
            arr1[i + 1] = (arr1[i] + arr1[i + 1]) % MOD;
        }
        if (arr2[i] == 1 || arr2[i + 1] == 1) {
            arr2[i + 1] = (arr2[i] + arr2[i + 1]) % MOD;
        } else {
            arr2[i + 1] = (arr2[i] * arr2[i + 1]) % MOD;
        }
        sort(arr1 + i + 1, arr1 + N);
        sort(arr2 + i + 1, arr2 + N);
    }
    cout << arr1[N - 1] << "\n" << arr2[N - 1] << "\n";
    return 0;
}