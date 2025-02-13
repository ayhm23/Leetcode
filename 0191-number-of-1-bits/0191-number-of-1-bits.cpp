class Solution {
public:
    int count(int left, int right, uint32_t n){
        if(left == right){
            if((n >> (31-left)) & 1){
                return 1;
            }
            else{
                return 0;
            }
        }
        int mid = (left + right)/2;
        int countleft = count(left, mid, n);
        int countright = count(mid + 1, right, n);

        return countleft + countright;
        
    }

    int hammingWeight(int n) {
        bitset<32> binary(n);
        return count(0, 31, n);
    }
};