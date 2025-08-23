class Solution {
public:
    string leftshift(string s){
        char c = s.front();       // first character
        s.erase(s.begin());       // remove first char
        return s + c;             // append to end
    }

    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;

        string demo = s;
        for (int i = 0; i < s.length(); i++) {
            if (demo == goal) return true;
            demo = leftshift(demo);
        }
        return false;
    }
};
