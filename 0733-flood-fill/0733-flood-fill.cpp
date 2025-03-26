class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startingCol = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        vector<int> vis(n, 0);
        vector<vector<int>> visited(m, vis);
        queue<pair<int,int>> q;

        visited[sr][sc] = 1;
        image[sr][sc] = color;
        q.push({sr,sc});                

        //BFS
        vector<int> delrow = {0,-1,0,1};
        vector<int> delcol = {-1,0,1,0};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i = 0;i < delrow.size(); i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                            visited[nrow][ncol] == 0 && image[nrow][ncol] == startingCol){
                                visited[nrow][ncol] = 1;
                                image[nrow][ncol] = color;
                                q.push({nrow,ncol});
                            }
            }
        }
    return image;
    }

};