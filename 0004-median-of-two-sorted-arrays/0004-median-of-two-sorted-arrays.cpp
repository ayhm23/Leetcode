class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int median = (n1 + n2 + 1)/2; 
        int lo1 = 0, lo2 = 0, hi1 = n1, hi2 = n2;

        while(lo1 <= hi1 && lo2 <= hi2){
            int cut1 = lo1 + (hi1-lo1)/2, cut2 = median - cut1;

            int l1 = cut1 != 0 ? nums1[cut1-1] : INT_MIN;
            int l2 = cut2 != 0 ? nums2[cut2-1] : INT_MIN;
            int r1 = cut1 != n1 ? nums1[cut1] : INT_MAX;
            int r2 = cut2 != n2 ? nums2[cut2] : INT_MAX; 

            if(l1 <= r2 && l2 <= r1){
                if ((n1 + n2) % 2) // odd
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            else{
                if(l1 > r2) hi1 = cut1-1;
                else if(l2 > r1) lo1 = cut1 + 1;
            }
        }
        return 0.0;
    }
};