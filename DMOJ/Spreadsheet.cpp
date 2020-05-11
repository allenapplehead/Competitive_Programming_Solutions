#include <bits/stdc++.h>
using namespace std;

bool visited[10][9];
string spreadsheet[10][9];
int ans[10][9];
int vis[10][9];

int dfs(int row, int col, int vis[10][9]) {
    // define base cases
    bool isInt = true;
    for (int i = 0; i < spreadsheet[row][col].length(); ++i) {
        if (spreadsheet[row][col][i] < 48 || spreadsheet[row][col][i] > 57) {
            isInt = false;
            break;
        }
    }
    // base case 1: it is an integer already
    if (isInt) {
        stringstream si(spreadsheet[row][col]);
        si >> ans[row][col];
        return ans[row][col];
    } else {
        vector<string> command;
        string s = "";
        for (int i = 0; i < spreadsheet[row][col].length(); ++i) {
            if (spreadsheet[row][col][i] == ' ') {
                command.push_back(s);
                s = "";
            }
        }
        // debug
        cout << "DEBUG: " << '\n';
        for (int i = 0; i < command.size(); ++i) {
            cout << command[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // get the input
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> spreadsheet[i][j];
        }
    }
    // this looks like a flood fill problem and recusion
    // code: go through all the cells and try to fill them all
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!visited[i][j]) {
                
            }
        }
    }
    return 0;
}