class Solution {
public:
    string longestNiceSubstring(string s) {
        //convert to unordered set for O(1) comaparisions
        if (s.length() < 2) return "";  // A single character cannot be nice
        
        unordered_set<char> charset(s.begin(), s.end());

        //find the point i where the nice substring fails
        for(int i = 0; i < s.length(); i++){
            if(charset.count(tolower(s[i])) && charset.count(toupper(s[i]))){
                continue; 
            }
            else{
                string left = longestNiceSubstring(s.substr(0,i));
                string right = longestNiceSubstring(s.substr(i+1));

                return left.size() >= right.size() ? left : right;
            }
        }

        return s;
    }
};