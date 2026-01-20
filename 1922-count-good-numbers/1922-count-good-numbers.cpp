class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        if (b == 0) return 1;

        long long half = power(a, b / 2);
        long long res = (half * half) % MOD;

        if (b % 2)
            res = (res * a) % MOD;

        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // even indices
        long long odd  = n / 2;       // odd indices

        return (power(5, even) * power(4, odd)) % MOD;
    }
};
