class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];
        if(strs.size() == 1) return common;
        for(int i = 1; i < strs.size(); i++){
            string next = strs[i];
            string match = "";
            for(int j = 0; j < common.length(); j++){
                if(next.length() > j && common[j] == next[j]){
                    match.push_back(common[j]);
                }
                else{
                    break;
                }
            }
            common = match;
            if(common.length() == 0){
                return "";
            }
        }
        return common;
    }
};