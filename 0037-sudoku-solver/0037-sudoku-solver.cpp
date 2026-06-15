class Solution {
public:
    bool check(vector<vector<char>>& board, char n, int x, int y){
        // check if n can be placed at x, y;
        int row = x / 3, col = y / 3;

        for(int i = 0; i < 9; i++){
            if(board[x][i] == n || board[i][y] == n) return false;
        }
        for(int i = 3*row; i < 3*(row+1); i++){
            for(int j = 3*col; j < 3*(col+1); j++){
                if(board[i][j] == n) return false;
            }
        }
        return true;
    } 
    bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (check(board, c, i, j)) {
                        board[i][j] = c;

                        if (solve(board))
                            return true;

                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true; // no empty cells left
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}
    
};