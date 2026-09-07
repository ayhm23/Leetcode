class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = s;
        int n = s.length();

        int cnt = 0;
        int bestL = 0;
        int bestLen = INT_MAX;
        for(int l = 0, r = 0; r < n; r++){
            if(s[r] == '1') cnt++;

            while(cnt == k){
                int curLen = r - l + 1;
                if(curLen < bestLen){
                    bestL = l;
                    bestLen = curLen;
                }
                else if(curLen == bestLen && s.compare(l, curLen, s, bestL, bestLen) < 0){
                    bestL = l;
                    bestLen = curLen;
                }
                if(s[l] == '1') cnt--;
                l++;
            }
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen); 
    }
};