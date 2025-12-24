class Solution {
public:
    int maxDepth(string s) {
        int maxx = 0, count = 0;
        for(char c : s){
            if(c == '(') {
                count += 1;
                maxx = max(maxx, count);
            }
            else if (c == ')') count -= 1;
            else{
                continue;
            }
        }
        return maxx;
    }
};