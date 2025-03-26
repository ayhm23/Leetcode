class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>>surr(m, vector<char>(n, 'X'));
        vector<pair<int,int>> edge;
        for(int row = 0; row < m; row++){
            for(int col = 0;col < n; col++){
                if(board[row][col] == 'O' && (row == 0 || row == m-1 || col == 0 || col == n-1)){
                    surr[row][col] = 'O';
                    edge.push_back({row,col});
                }
            }
        }
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        
        for(pair<int,int> start : edge){
            int row = start.first, col = start.second;
            stack<pair<int,int>> s;
            s.push({row,col});
            while(!s.empty()){
                int row = s.top().first;
                int col = s.top().second;
                s.pop();
            for(int i = 0;i < 4; i++){
                int nrow = row + delrow[i], ncol = col + delcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    if(board[nrow][ncol] == 'O' && surr[nrow][ncol] == 'X'){
                        surr[nrow][ncol] = 'O';
                        s.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        board = surr;
    }
};