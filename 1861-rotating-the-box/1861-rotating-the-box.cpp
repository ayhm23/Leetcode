class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0; i <= m-1; i++){
            deque<char> st;
            for(int j = n-1; j >= 0; j--){
                char c = boxGrid[i][j];
                if(c == '#'){
                    while(!st.empty() && st.front() == '.') st.pop_front();
                }
                if(c == '*'){
                    while(st.size() != n-1-j){
                        st.push_front('.');
                    }
                }
                st.push_front(c);
            }
            int j = n-1;
            while(!st.empty() && j >= 0){
                ans[j][m-1-i] = st.back();
                st.pop_back(); j--;
            }
        }
        return ans;
    }
};