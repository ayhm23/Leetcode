// class Solution {
// public:
//     int candy(vector<int>& ratings) {
        
//         int n = ratings.size();
//         vector<pair<int,int>> arr;
        
//         for(int i = 0; i < n; i++){
//             arr.push_back({ratings[i], i});
//         }

//         sort(arr.begin(), arr.end());

//         vector<int> candies(n, 1);

//         for(auto &p : arr){

//             int rating = p.first;
//             int i = p.second;

//             int left = 0, right = 0;

//             if(i > 0 && rating > ratings[i-1]){
//                 left = candies[i-1];
//             }

//             if(i < n-1 && rating > ratings[i+1]){
//                 right = candies[i+1];
//             }

//             candies[i] = max(left, right) + 1;
//         }

//         return accumulate(candies.begin(), candies.end(), 0);
//     }
// };

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        if(n == 1) return 1;
        //two pass O(n) approach
        vector<int> candies(n, 1);

        //left pass
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
        }

        //right pass

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int count = accumulate(candies.begin(), candies.end(), 0);
        return count;
    }
};