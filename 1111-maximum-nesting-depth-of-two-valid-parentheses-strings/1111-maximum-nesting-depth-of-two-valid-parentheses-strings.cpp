class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        
        int maxi = 0, cur = 0;
        for(int i = 0; i < n; i++){
            char c = seq[i];
            int p = c == ')' ? -1 : 1;

            cur += p;
            maxi = max(maxi, cur);
        }

        stack<pair<int, int>> st;

        int target = (maxi+1)/2;

        int nxt = 0;
        vector<int> ans (n, 0);
        cur = 0;
        for(int i = 0; i < n; i++){
            int ch = seq[i];
            int p = ch == ')' ? -1 : 1;

            if(ch == '('){
                if(cur < target){
                    cur += p;
                    st.push({i, 0});
                }
                else{
                    st.push({i, 1});
                }
            } 
            else{
                //ch == ')'
                auto [ind, x] = st.top(); st.pop();
                
                ans[ind] = x;
                ans[i] = x;
                
                if(x == 0){
                    cur += p;
                }
            }
        }
        return ans;
    }
};