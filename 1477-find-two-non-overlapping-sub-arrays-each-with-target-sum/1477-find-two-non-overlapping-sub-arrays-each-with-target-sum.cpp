class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> left(n+1, n+1);

        //dp[i]stores the number of target subarrays with min length
        int minLen = n+1;
        
        int sum = 0;
        for(int l = 0, r = 0; r < n; r++){
            sum += arr[r];
            left[r+1] = left[r]; 
            while(sum > target && l <= r){
                sum -= arr[l++];
            }
            if(sum == target){
                minLen = min(minLen, r - l + 1);
                left[r+1] = min(left[r+1], minLen);
            }
        }

        for(int i = 0; i <= n; i++){
            cout << left[i] << " ";
        }

        vector<int> right(n+1, n+1);

        //dp[i]stores the number of target subarrays with min length
        minLen = n+1;
        
        sum = 0;
        int l = n;
        for(int r = n; r > 0; r--){
            sum += arr[r-1];
            right[r-1] = right[r]; 
            while(sum > target && l >= r){
                sum -= arr[l-1];
                l--;
            }
            if(sum == target){
                minLen = min(minLen, l - r + 1);
                right[r-1] = min(right[r-1], minLen);
            }
        }
        cout << endl;
        for(int i = 0; i <= n; i++){
            cout << right[i] << " ";
        }
        int ans = n+1;

        for(int i = 0; i <= n; i++){
            ans = min(ans, left[i] + right[i]);
        }
        return ans > n ? -1 : ans;
    }
};