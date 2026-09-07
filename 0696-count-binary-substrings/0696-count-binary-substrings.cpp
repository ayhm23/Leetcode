class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 0;
        int n = s.length();
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]) continue;

            int l = i, r = i + 1;

            while(l >= 0 && r < n && s[l] == s[i] && s[r] == s[i+1]){
                count++;
                l--; r++;
            }
        }

       
        return count;
    }
};