class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n = a.length(), m = b.length();

        vector<int> res(max(n, m) + 1, 0);

        int k = max(n, m);
        int i = n-1, j = m-1;

        while(i >= 0 || j >= 0){
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';

            res[k--] = sum % 2;
            carry = sum / 2;
        }

        res[k] = carry;

        string ans;
        int start = (res[0] == 0);

        for(int i = start; i < res.size(); i++)
            ans += char(res[i] + '0');

        return ans;
    }
};