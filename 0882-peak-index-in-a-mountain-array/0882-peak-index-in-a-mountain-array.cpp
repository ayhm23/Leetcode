class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mid == 0){
                if(n == 1 || arr[0] > arr[1]){
                    ans = 0;
                    return ans;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(mid == n-1){
                if(arr[n-1] > arr[n-2]){
                    ans = n-1;
                    return ans;
                }
                else{
                    high = mid - 1;
                }
            }
            else if(mid > 0 && mid < n-1){
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                    ans = mid;
                    return ans;
                }
                else if(arr[mid] < arr[mid+1]){
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }
        }   
        return ans;
    }
};