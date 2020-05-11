#include <bits/stdc++.h>
using namespace std;

map<char, int> look;
map<int, char> kool;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // init
    look.insert(make_pair('0', 0));
    look.insert(make_pair('1', 1));
    look.insert(make_pair('2', 2));
    look.insert(make_pair('3', 3));
    look.insert(make_pair('4', 4));
    look.insert(make_pair('5', 5));
    look.insert(make_pair('6', 6));
    look.insert(make_pair('7', 7));
    look.insert(make_pair('8', 8));
    look.insert(make_pair('9', 9));
    look.insert(make_pair('A', 10));
    look.insert(make_pair('B', 11));
    look.insert(make_pair('C', 12));
    look.insert(make_pair('D', 13));
    look.insert(make_pair('E', 14));
    look.insert(make_pair('F', 15));

    kool.insert(make_pair(0, '0'));
    kool.insert(make_pair(1, '1'));
    kool.insert(make_pair(2, '2'));
    kool.insert(make_pair(3, '3'));
    kool.insert(make_pair(4, '4'));
    kool.insert(make_pair(5, '5'));
    kool.insert(make_pair(6, '6'));
    kool.insert(make_pair(7, '7'));
    kool.insert(make_pair(8, '8'));
    kool.insert(make_pair(9, '9'));
    kool.insert(make_pair(10, 'A'));
    kool.insert(make_pair(11, 'B'));
    kool.insert(make_pair(12, 'C'));
    kool.insert(make_pair(13, 'D'));
    kool.insert(make_pair(14, 'E'));
    kool.insert(make_pair(15, 'F'));

    int T = 10;
    while (T--) {
        vector<string> board(16);
        for (int i = 0; i < 16; ++i) {
            cin >> board[i];
        }
        // simulate
        int ans = 0;
        bool vis[16];
        for (int i = 0; i < 16; ++i) {
            for (int j = 0; j < 16; ++j) {
                if (board[i][j] == '-') {
                    memset(vis, false, sizeof(vis));
                    for (int row = 0; row < 16; ++row) {
                        if (board[row][j] != '-') {
                            vis[look[board[row][j]]] = true;
                        }
                    }
                    for (int col = 0; col < 16; ++col) {
                        if (board[i][col] != '-') {
                            vis[look[board[i][col]]] = true;
                        }
                    }
                    int qx = (j / 4) * 4;
                    int qy = (i / 4) * 4;
                    for (int qrow = qy; qrow < qy + 4; qrow++) {
                        for (int qcol = qx; qcol < qx + 4; qcol++) {
                            if (board[qrow][qcol] != '-') 
                                vis[look[board[qrow][qcol]]] = true;
                        }
                    }
                    for (int k = 0; k < 16; ++k) {
                        if (vis[k] == false) {
                            board[i][j] = kool[k];
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}