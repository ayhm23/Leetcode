class Solution {
public:
    using ll = long long;

    int divide(int dividend, int divisor) {

        ll d = abs((ll)dividend);
        ll n = abs((ll)divisor);

        bool isNeg = (dividend < 0) ^ (divisor < 0);

        ll q = 0;

        while(d >= n){

            int cnt = 0;

            // find greatest power of 2 such that n * 2^cnt <= d
            while(d >= (n << (cnt + 1))){
                cnt++;
            }

            q += (1LL << cnt);       // use long long shift
            d -= (n << cnt);
        }

        if(isNeg)
            q = -q;

        // overflow case
        if(q > INT_MAX)
            return INT_MAX;

        if(q < INT_MIN)
            return INT_MIN;

        return (int)q;
    }
};