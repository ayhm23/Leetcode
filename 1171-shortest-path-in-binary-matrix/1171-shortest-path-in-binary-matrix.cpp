class Solution {

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1]== 1) return -1;

        vector<vector<int>> visited (n, vector<int>(n, 0));
        queue<pair<int,int>>q;
        vector<vector<int>> path (n, vector<int>(n, -1));

        visited[0][0] = 1;
        path[0][0] = 1;
        q.push({0,0});

        while(!q.empty()){
            pair<int,int> curr = q.front(); 
            int currX = curr.first;
            int currY = curr.second; 
            q.pop();

            for(int i = -1;i <= 1; i++){
                for(int j = -1;j <= 1; j++){
                    if(i == 0 && j == 0) continue;

                    int adjX = currX + i;
                    int adjY = currY + j;
                    
                    if(adjX >= 0 && adjX <= n-1 && adjY >= 0 && adjY <= n-1
                        && visited[adjX][adjY] != 1 && grid[adjX][adjY] == 0){
                            q.push({adjX,adjY});
                            visited[adjX][adjY] = 1;
                            path[adjX][adjY] = path[currX][currY] + 1;
                    }
                }   
            }
        }
    return path[n-1][n-1];
    }
};