class Solution {
public:
    vector<int> drow = {0, -1, 0, 1};
    vector<int> dcol = {-1, 0, 1, 0};

    bool check(vector<vector<char>>& board, string& word,
               int i, int row, int col) {

        if (i == word.size()) return true;

        char temp = board[row][col];
        board[row][col] = '#';   // mark visited

        for (int d = 0; d < 4; d++) {
            int nr = row + drow[d];
            int nc = col + dcol[d];

            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size() &&
                board[nr][nc] == word[i]) {

                if (check(board, word, i + 1, nr, nc))
                    return true;
            }
        }

        board[row][col] = temp;  // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == word[0]) {
                    if (check(board, word, 1, r, c))
                        return true;
                }
            }
        }
        return false;
    }
};
