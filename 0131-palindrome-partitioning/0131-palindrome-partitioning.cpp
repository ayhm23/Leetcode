class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string s){
        int n = s.length();
        int l = 0, r = n-1;
        while(l <= r && l < s.length() && r >= 0){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void part(int i, vector<string> &curr, const string& s){
        if(i == s.size()){
            ans.push_back(curr); return;
        }
        for(int j = i ; j < s.size(); j++){
            string sub = s.substr(i, j - i + 1);
            if(isPal(sub)){
                curr.push_back(sub);
                part(j + 1, curr, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        //left, ind, right
        vector<string> curr;
        part(0, curr, s);
        return ans;
    }
};