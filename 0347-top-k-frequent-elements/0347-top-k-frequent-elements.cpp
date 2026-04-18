class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store by freq, num in unordered map
        unordered_map<int, int> mp;

        for(int i : nums) mp[i]++;

        priority_queue<pair<int, int>> pq;
        for(auto &[num, freq] : mp){
            pq.push({freq, num});
        }

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second); 
            pq.pop();
        }
        return ans;
    }
};