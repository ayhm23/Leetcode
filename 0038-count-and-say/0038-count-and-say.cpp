class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        
        string s = countAndSay(n-1);

        //RLE
        int l = 0, currL = 0, r = 0;
        string enc = "";
        while(r < s.length()){
            char curr = s[l];
            while(r < s.length() && s[r] == curr) r++;
            int len = r - l;
            string temp = to_string(len) + curr;
            enc += temp;
            l = r;
        }
        return enc;
    }
};