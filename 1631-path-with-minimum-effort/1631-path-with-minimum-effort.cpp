class Solution {
public:
    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        using T = tuple<int, int, int>;

        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<T, vector<T>, greater<T>> minH;

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0;

        minH.push({0, 0, 0});

        while(!minH.empty()){

            auto [currEffort, x, y] = minH.top();
            minH.pop();

            if(currEffort > effort[x][y]) continue;

            if(x == rows - 1 && y == cols - 1)
                return currEffort;

            for(int i = 0; i < 4; i++){

                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX < 0 || newY < 0 || newX >= rows || newY >= cols)
                    continue;

                int newEffort = max(currEffort,
                                    abs(heights[x][y] - heights[newX][newY]));

                if(newEffort < effort[newX][newY]){
                    effort[newX][newY] = newEffort;
                    minH.push({newEffort, newX, newY});
                }
            }
        }

        return -1;
    }
};