class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // (i, j) --> (j, n - i - 1)
        // step1 : transpose (i, j) --> (j, i)
        // step2 : reverse row (j, i) --> (j, n - i - 1)

        //transpose

        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};