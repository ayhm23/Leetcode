class Solution {
public:
    unordered_map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int romanToInt(string s) {
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // If current value < next value, subtract instead of add
            if (i + 1 < n && romanMap[s[i]] < romanMap[s[i+1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};
