class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long ans = 0;
        int i = 0;
        int sign = 1;

        // 1) Skip whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2) Handle optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3) Process digits
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4) Overflow handling
            if (ans * sign >= INT_MAX) return INT_MAX;
            if (ans * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return ans * sign;
    }
};
