class Solution {
public:
    typedef long long ll;
    ll MOD = INT_MAX;
    int n;

    
    ll atoi(const string& s, ll val, int i){
        if(i == n) return val;
        ll temp = s[i] - '0';
        if(!(temp >= 0 && temp <= 9)) return val;

        ll tempVal = val * 10 + temp;
        if(tempVal > MOD) return MOD;

        return atoi(s, tempVal, i+1);
    }
    int myAtoi(string s) {
        int i = 0, sign = 1;
        n = s.length();
        while(i < n &&s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        MOD = (sign == 1) ? (ll)INT_MAX : (ll)INT_MAX + 1;

        ll val = atoi(s, 0, i);

        return sign * val;
    }
};