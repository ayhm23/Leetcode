class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return strs[0];

        string ans = strs[0];

        for(int i = 1; i < n; i++){
            string match = "";
            string next = strs[i];
            for(int j = 0; j < ans.length(); j++){
                if(j < next.length() && ans[j] == next[j]){
                    match.push_back(ans[j]);
                    continue;
                }
                else{
                    break;
                }
            }
            ans = match;
            if(ans.length() == 0) return "";
        }
        return ans;
    }
};