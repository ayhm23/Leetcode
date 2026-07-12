class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> isP(n, true);

        isP[0] = isP[1] = false;

        for(int i = 2; i * i < n; i++) {
            if(isP[i]) {
                for(int j = i * i; j < n; j += i) {
                    isP[j] = false;
                }
            }
        }

        int cnt = 0;

        for(int i = 2; i < n; i++) {
            if(isP[i])
                cnt++;
        }

        return cnt;
    }
};