class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // approach 1.. two nested look.. i and i to n -1 O(n^2) O(1)
        // approach 2.. hashing (index, value)initially.. look for target - nums[i] in hashmap...O(N) and O(N)
        // approach 3.. vector<pair(value,index)> sort by values.. for ith value use binary search for target - nums[i] O(NlogN) O(N)

        unordered_map<int,int> map;
        
        for(int i = 0; i < nums.size(); i++){
            int x = target - nums[i];

            if(map.find(x) != map.end()){
                return {map[x], i};
            }
            map[nums[i]] = i;
        }
    return {};
    }
};