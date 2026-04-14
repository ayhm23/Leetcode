class Solution {
public:
    void heapify(vector<int>& nums, int n, int i){
        int largest = i;

        int r = 2*i + 2, l = 2*i + 1;
        if(r < n && nums[r] > nums[largest]) largest = r;
        if(l < n && nums[l] > nums[largest]) largest = l;

        if(largest != i){
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    void makeMaxHeap(vector<int>& nums, int n){
        for(int i = (n-1)/2; i >= 0; i--){
            heapify(nums, n, i); // ✅ fixed
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        makeMaxHeap(nums, n);

        for(int i = 1; i < k; i++){
            swap(nums[0], nums[nums.size()-1]); // ✅ fixed
            nums.pop_back();
            heapify(nums, nums.size(), 0);
        }
        return nums[0];
    }
};