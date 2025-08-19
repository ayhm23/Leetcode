class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2;
        int half = (total + 1) / 2;

        int lo = 0, hi = n1;

        while (lo <= hi) {
            int cut1 = (lo + hi) / 2;       // partition in nums1
            int cut2 = half - cut1;         // partition in nums2

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2) {
                hi = cut1 - 1;
            }
            else {
                lo = cut1 + 1;
            }
        }
        return 0.0; // never reached
    }
};