// class Solution {
// public:
//     int ans = 0;
//     vector<vector<int>> dp;
//     int count(string s, int k, int left, int ind){
//         //odd len
//         if(ind >= s.length()){
//             return 0;
//         }

//         if(dp[ind][left] != -1) return dp[ind][left];

//         int i = ind;
//         int l = i, r = i;
//         bool isKPal = false;
        
//         while(l >= left && r < s.length() && s[l] == s[r]){
//             l--; r++;
//             if(r - l - 1 >= k){
//                 isKPal = true; break;
//             }
//         }
        
//         if(isKPal){
//             dp[ind][left] = max(dp[ind][left] , 1 + count(s, k, r, r));
//         }

//         //even len
//         l = i, r = i+1;
//         bool isKPal2 = false;

//         while(l >= left && r < s.length() && s[l] == s[r]){
//             l--; r++;
//             if(r - l - 1 >= k){
//                 isKPal2 = true; break;
//             }
//         }
//         if(isKPal2){
//             dp[ind][left] = max(dp[ind][left] , 1 + count(s, k, r, r));
//         }

//         if(!isKPal2 || !isKPal){
//             dp[ind][left] = max(dp[ind][left] , count(s, k, left, ind+1));
//         }
//         return dp[ind][left];
//     }
//     int maxPalindromes(string s, int k) {
//         ans = 0;
//         int n = s.length();
//         dp.assign(n+1, vector<int>(n+1, -1));
//         return count(s, k, 0, 0);
        
//     }
// };

class Solution {
public:
    
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> isPal(n, vector<bool>(n, false)); //l, r forms a palindrome

        
        
        //o(n^2)
        for(int len = 1; len <= n; len++){
            for(int l = 0; l < n; l++){
                int r = l + len - 1;

                if(r < n && s[l] == s[r] && (len <= 2 || isPal[l+1][r-1]) == true){
                    isPal[l][r] = true;
                }
            }
        }
        
        vector<int> dp(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            dp[i] = dp[i+1]; //skip

            for(int j = i + k - 1; j < n; j++){
                if(isPal[i][j] == true){
                    dp[i] = max(dp[i], 1 + dp[j+1]);
                }
            }
        }

        return dp[0];

    }
};