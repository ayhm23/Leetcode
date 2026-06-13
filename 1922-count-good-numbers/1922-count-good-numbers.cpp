class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9 + 7;

    ll power(ll base, ll exp) {
        if (exp == 0) return 1;

        ll half = power(base, exp / 2);
        half = (half * half) % MOD;

        if (exp % 2)
            return (half * base) % MOD;
        else
            return half;
    }

    int countGoodNumbers(long long n) {
        // {0, 2, 4, 6, 8} -- even inices
        // {2, 3, 5, 7} -- odd indices

        ll odd = n / 2;
        ll even = (n + 1)/2; 

        return (power(5, even) * power(4, odd)) % MOD;
    }
};