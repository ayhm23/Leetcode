class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ref = strs[0];
        int j = ref.size();
        for(int i = 0; i < strs.size(); i++){
            for(int k = 0; k < j; k++){
                if(ref[k] == strs[i][k]) continue;
                else{
                    j = k; break;
                }
            }
        }
        return ref.substr(0, j);
    }
};