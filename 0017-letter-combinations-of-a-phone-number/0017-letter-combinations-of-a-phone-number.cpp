class Solution {
public:
    vector<string> ans;
    const string map [8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void mapper(string curr, int ind, const string& digits){
        if(ind == digits.length()){
            ans.push_back(curr);
            return;
        }
        string s = map[digits[ind] - '2'];

        for(int i = 0; i < s.length(); i++){
            curr.push_back(s[i]);
            mapper(curr, ind+1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        string s = "";
        mapper(s, 0, digits);
        return ans;
    }
};