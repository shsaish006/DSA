#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool row[9][9], col[9][9], block[3][3][9];
    vector<pair<int,int>> t;
    bool ok;

    void dfs(vector<vector<char>>& board, int k) {
        if (k == t.size()) {
            ok = true;
            return;
        }
        int i = t[k].first, j = t[k].second;
        for (int v = 0; v < 9; v++) {
            if (!row[i][v] && !col[j][v] && !block[i/3][j/3][v]) {
                row[i][v] = col[j][v] = block[i/3][j/3][v] = true;
                board[i][j] = v + '1';
                dfs(board, k + 1);
                if (ok) return;
                row[i][v] = col[j][v] = block[i/3][j/3][v] = false;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        ok = false;
        t.clear();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    t.push_back({i, j});
                } else {
                    int v = board[i][j] - '1';
                    row[i][v] = col[j][v] = block[i/3][j/3][v] = true;
                }
            }
        }
        dfs(board, 0);
    }
};
