class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;       // prefix sum 0 occurs once before array starts

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;              // current prefix sum

            int need = sum - k;     // we need a previous prefix equal to this
            if (map.find(need) != map.end()) {
                count += map[need];
            }

            map[sum]++;            // record this prefix sum
        }

        return count;
    }
};
