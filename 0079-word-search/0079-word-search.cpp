class Solution {
public:
    vector<vector<int>> vis;
    int dx [4] = {0, -1, 0, 1};
    int dy [4] = {-1, 0, 1, 0};
    bool dfs(const vector<vector<char>> &board, const string& word, int ind, int x, int y){
        //found index at x, y
        vis[x][y] = 1;

        if(ind == word.size()-1) return true;
        
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newY >= 0 && newX < board.size() && newY < board[0].size() 
             && !vis[newX][newY]){  
                if(word[ind+1] == board[newX][newY]){
                    if(dfs(board, word, ind + 1, newX, newY)) return true;
                }
            }
        }
        vis[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vis.assign(m, vector<int> (n, 0));
        bool ans = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    //starting point
                    if(dfs(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};