class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //sum of first k element...then we removve the right most from start in winodw and add from back
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int n = cardPoints.size();
        if(n == k) return sum;

        int ans = sum;

        int left = k-1, right = n-1;
   
        while(left >= 0){
            sum = sum - cardPoints[left] + cardPoints[right];
            ans = max(sum, ans);
            left--; right--;
        }
        return ans;
    }
};