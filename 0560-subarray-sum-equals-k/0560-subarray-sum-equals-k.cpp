class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sol1 : make all subarrays O(N^2) O(N^2)
        // sol2 : prefix sum O(N^2) O(N)
        // sol3 : hashmap to keep count of exisitng sum

        unordered_map <int, int> map; 
        map[0] = 1;
        int n = nums.size();
        int sum = 0, count = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            int x = sum - k;
            if(map.find(x) != map.end()){
                count += map[x];
            }
            map[sum]++;
        }
    return count;
    }
};