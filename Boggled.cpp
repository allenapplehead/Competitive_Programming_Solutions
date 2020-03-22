#include <bits/stdc++.h>
using namespace std;

set<string> used;
char board[4][4];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, 1, 0, -1};

bool visited[4][4];

bool solve(string word, int r, int c, int level) {
    // try to find the word in the board
    visited[r][c] = true;
    if (level == word.length() - 1) {
        return true;
    }
    bool found = false;
    for (int i = 0; i < 8; ++i) {
        if (r + dy[i] < 4 && r + dy[i] >= 0 && c + dx[i] < 4 && c + dx[i] >= 0) {
            if (board[r + dy[i]][c + dx[i]] == word[level + 1] && !visited[r + dy[i]][c + dx[i]]) {
                if (!found) {
                    found = solve(word, r + dy[i], c + dx[i], level + 1);
                }
            }
        }
    }
    if (!found) visited[r][c] = false;
    return found;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    const int ROUNDS = 5;
    for (int i = 0; i < ROUNDS; ++i) {
        // get the board first
        for (int ii = 0; ii < 4; ++ii) {
            for (int jj = 0; jj < 4; ++jj) {
                cin >> board[ii][jj];
            }
        }
        // resets
        int score = 0, good = 0, too_short = 0, repetition = 0, not_found = 0;
        used.clear();
        int words; cin >> words;
        for (int k = 0; k < words; ++k) {
            string s;
            cin >> s;
            // 4 classifications: good, too short, repetition, not found
            // this is ordered in terms of priority as well
            if (s.length() < 3) {
                too_short++;
            } else if (used.find(s) != used.end()) {
                repetition++;
            } else {
                // try to find the word
                used.insert(s);
                bool found = false;
                for (int ii = 0; ii < 4 && !found; ++ii) {
                    for (int jj = 0; jj < 4 && !found; ++jj) {
                        if (board[ii][jj] == s[0]) {
                            for (int i = 0; i < 4; ++i) {
                                for (int j = 0; j < 4; ++j) {
                                    visited[i][j] = false;
                                }
                            }
                            if (solve(s, ii, jj, 0)) {
                                found = true;
                                good++;
                                // calculate the score
                                if (s.length() == 3 || s.length() == 4) score++;
                                else if (s.length() == 5) score += 2;
                                else if (s.length() == 6) score += 3;
                                else if (s.length() == 7) score += 4;
                                else score += 11; 
                            } else {
                                //cout << "DEBUG: " << s << " " << ii << " " << jj << '\n';
                            }
                        }
                    }
                }
                if (!found) {
                    not_found++;
                }
            }
        }
        // display the summary
        cout << "Your score: " << score << " (" << good << " good, " << not_found << " not found, " << too_short << " too short, " << repetition << " repeated)" << '\n';
    }
    

    return 0;
}