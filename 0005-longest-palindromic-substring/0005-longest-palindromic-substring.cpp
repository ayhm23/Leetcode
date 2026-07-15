class Solution {
public:
    string longestPalindrome(string s) {
        //expand right // expand left from center
        //(i, i) for odd
        //(i, i + 1) for even
        int n = s.length();
        if(n <= 1) return s;
        int ansL = -1, ansR = -1, curlen = 0, bestlen = 0;
        for(int i = 0; i < n-1; i++){
            //odd case
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                curlen = (r - l + 1);
                l--; r++;
            }
            if(curlen > bestlen){
                bestlen = curlen;
                ansL = l+1;
                ansR = r-1;
            }

            //even case
            l = i, r = i + 1;
            if(s[l] == s[r]){
                while(l >= 0 && r < n && s[l] == s[r]){
                    curlen = (r - l + 1);
                    l--; r++;
                }

                if(curlen > bestlen){
                    bestlen = curlen;
                    ansL = l+1;
                    ansR = r-1;
                }
            }
        }
        string ans = s.substr(ansL, bestlen);
        return ans;
    }
};