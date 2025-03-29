#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> path(row, vector<int>(col, INT_MAX));

        pq.push({0, {0, 0}});  // Start with 0 effort at (0,0)
        path[0][0] = 0;

        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};

        while (!pq.empty()) {
            int maxEffort = pq.top().first;
            int currX = pq.top().second.first;
            int currY = pq.top().second.second;
            pq.pop();

            if (currX == row - 1 && currY == col - 1) {
                return maxEffort;  // Reached the destination
            }

            for (int i = 0; i < 4; i++) {
                int adjX = currX + delrow[i];
                int adjY = currY + delcol[i];

                if (adjX >= 0 && adjX < row && adjY >= 0 && adjY < col) {
                    int adjEffort = abs(heights[adjX][adjY] - heights[currX][currY]);
                    int newEffort = max(maxEffort, adjEffort);

                    if (newEffort < path[adjX][adjY]) {
                        path[adjX][adjY] = newEffort;
                        pq.push({newEffort, {adjX, adjY}});
                    }
                }
            }
        }
        return 0; // Should never reach here
    }
};
