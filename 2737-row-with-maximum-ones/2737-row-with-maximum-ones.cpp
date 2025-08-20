class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxOnes = -1;
        int rowIndex = -1;

        for (int i = 0; i < m; ++i) {
            int onesCount = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) onesCount++;
            }
            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                rowIndex = i;
            }
        }

        return {rowIndex, maxOnes};
    }
};