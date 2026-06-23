class Solution {
public:
    bool checkValidString(string s) {
        //lo = min possible open vbrackets, // hi = max possible open brackets
        int lo = 0, hi = 0;
        for(char c : s){
            if(c == '('){
                lo++; hi++;
            }
            else if(c == ')'){
                lo--; hi--;
            }
            else{
                if(lo > 0) lo--;
                hi++;
            }
            if(hi < 0) return false; //impossible to come back
            lo = max(lo, 0); //using * fot only (
        }
        return lo == 0;
    }
};