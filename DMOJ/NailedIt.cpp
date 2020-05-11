#include <bits/stdc++.h>
using namespace std;

int ans1 = 0, ans2 = 0;
int freq[2001];
int sums[4001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  for (int inp, i = 0; i < n; i++) {
    cin >> inp;
    freq[inp]++;
  }
  for (int i = 1; i < 2001; i++) {
    if (freq[i]) {
      for (int j = i; j < 2001; j++) {
        if (i == j) {
          sums[i * 2] += freq[i] >> 1;
        } else if (freq[j]) {
          sums[i + j] += min(freq[i], freq[j]);
        }
      }
    }
  }
  for (int i = 4000; i >= 0; i--) {
    if (sums[i] > ans1) {
      ans2 = 1;
      ans1 = sums[i];
    } else if (sums[i] == ans1) {
      ans2++;
    }
  }
  cout << ans1 << " " << ans2 << '\n';
  return 0;
}