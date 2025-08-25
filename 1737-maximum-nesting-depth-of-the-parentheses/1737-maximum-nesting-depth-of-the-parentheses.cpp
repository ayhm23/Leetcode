class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, count = 0;
        for(char c : s){
            if(c == '(') count++;
            else if(c == ')') count--;

            depth = max(depth, count);
        }
        return depth;
    }
};