class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int totalLeft = (n1 + n2 + 1) / 2;

        int l = 0, r = n1;

        while(l <= r){
            int cut1 = l + (r-l)/2;
            int cut2 = totalLeft - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // correct partition
            if(l1 <= r2 && l2 <= r1){

                // odd length
                if((n1+n2)%2)
                    return max(l1,l2);

                // even length
                return (max(l1,l2) + min(r1,r2))/2.0;
            }

            // too many elements from nums1
            else if(l1 > r2){
                r = cut1 - 1;
            }

            // too few elements from nums1
            else{
                l = cut1 + 1;
            }
        }

        return 0;
    }
};