class Solution {
public:
    int Area(vector<int>& nums){
        stack<int> st;
        int maxA = 0;
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int height = nums[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxA = 0;
        int n = matrix.size(), m = matrix[0].size(); 
        vector<int> heights (m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = Area(heights);
            maxA = max(maxA, area);
        }
        return maxA;
    }
};