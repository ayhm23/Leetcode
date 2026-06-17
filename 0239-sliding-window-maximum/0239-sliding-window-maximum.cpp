class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //deque
        deque<int> dq; // store indices
        vector<int> ans(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            while(!dq.empty() && dq.front() <= i - k) dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)ans[i-k+1] = nums[dq.front()];
        }
        return ans;
    }
};