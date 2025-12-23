class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        int j = -1;
        while(i >= 0){
            if((num[i] - '0') % 2 == 1){
                j = i;
                break;
            }
            else{
                i--;
            }
        }
        if(j == -1) return "";

        return num.substr(0, j + 1);
    }
};