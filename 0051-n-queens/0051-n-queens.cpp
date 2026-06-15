class Solution {
public:
    vector<vector<string>> ans;

    bool isValid(vector<string>& curr, int i, int j, int n) {
        // Check column
        for (int row = 0; row < i; row++) {
            if (curr[row][j] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int r = i - 1, c = j - 1; r >= 0 && c >= 0; r--, c--) {
            if (curr[r][c] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int r = i - 1, c = j + 1; r >= 0 && c < n; r--, c++) {
            if (curr[r][c] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int i, int n, vector<string>& curr) {
        if (i == n) {
            ans.push_back(curr);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isValid(curr, i, j, n)) {
                curr[i][j] = 'Q';
                solve(i + 1, n, curr);
                curr[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        solve(0, n, curr);
        return ans;
    }
};