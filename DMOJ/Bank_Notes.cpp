#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAXN = 201;
const int MAXK = 20001;
int N, K, c[MAXN], v[MAXN], dp[MAXN][MAXK];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("output.txt", "w", stdout);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> v[i];
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	cin >> K;
	for (int i = 1; i <= K; i++)
		dp[0][i] = 1e9;

	int curval;
	// main routine
	for (int i = 1; i <= N; i++)
	{
		for (int rem = 0; rem <= v[i] - 1; rem++) { // the possible remainders from dividing by v[i]
			deque<int> d; // memoizes the minimum values from the past iteration (multiples)
			for (int j = 0; j <= (K - rem) / v[i]; j++) { // loop thru all multiples of v[i] that are not greater than K
				curval = rem + v[i] * j; // might not be reachable
				if (dp[i - 1][curval] != 1e9) { // so yeah, that ^ explains this line (also because the states are "copied over" from transition to transition, because what is possible with n - 1 coins is for sure possible with n coins)
					while (!d.empty() && dp[i - 1][d.back() * v[i] + rem] + j - d.back() >= dp[i - 1][curval]) { // we pop elements in the deque greater than the current value
						d.pop_back();
					}
					d.push_back(j);
				}
				if (!d.empty() && j - d.front() > c[i]) // if d.front() from the previous iteration increased by more than what is allowed
					d.pop_front();
				if (d.empty())
					dp[i][curval] = 1e9;
				else
					dp[i][curval] = dp[i - 1][d.front() * v[i] + rem] + j - d.front();

				/* DEBUG */
				cout << "DP:: ";
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						cout << dp[i][j] << " ";
					}
					cout << "\n";
				}
				cout << "DEQUE:: ";
				for (int i = 0; i < d.size(); i++) {
					cout << d[i] << " ";
				}
				cout << "\n";
				cout << "i: " << i << " j: " << j << " rem: " << rem << " curval: " << curval << "\n";
				cout << "==================================================" << "\n\n";
			}
		}
	}
	cout << dp[N][K] << endl;
	return 0;
}