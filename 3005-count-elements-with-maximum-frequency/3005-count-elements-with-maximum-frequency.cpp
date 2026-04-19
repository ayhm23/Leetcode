// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int currE = nums[0], maxF = 0;
//         for(int i = 0; i < nums.size(); i++){
//             mp[nums[i]]++;
//             maxF = max(maxF, mp[nums[i]]);
//         }
//         int ans = 0;
//         for(auto &[num, count] : mp){
//             if(count == maxF){
//                 ans += maxF;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        int maxF = 0;
        int countMaxF = 0;

        for(int num : nums){
            mp[num]++;
            int freq = mp[num];

            if(freq > maxF){
                maxF = freq;
                countMaxF = 1;
            }
            else if(freq == maxF){
                countMaxF++;
            }
        }

        return maxF * countMaxF;
    }
};