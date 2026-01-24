class Solution {
public:
    bool check(vector<string>& board, int row, int col, int n) {
        // check left side of the row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, int col, int n, vector<string>& board) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (check(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(ans, col + 1, n, board);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string s(n, '.');   
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        solve(ans, 0, n, board);
        return ans;         
    }
};
