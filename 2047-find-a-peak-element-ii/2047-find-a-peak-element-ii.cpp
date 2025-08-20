class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Find max element in this column
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool left = (mid - 1 >= 0) && (mat[maxRow][mid - 1] > mat[maxRow][mid]);
            bool right = (mid + 1 < n) && (mat[maxRow][mid + 1] > mat[maxRow][mid]);

            if (!left && !right) {
                // Peak found
                return {maxRow, mid};
            } else if (left) {
                hi = mid - 1; // move left
            } else {
                lo = mid + 1; // move right
            }
        }
        return {-1, -1}; // should never reach
    }
};
