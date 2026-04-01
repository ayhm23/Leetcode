#define f(i, n) for(int i = 1; i <= n; i++)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(); int m = word2.length();
        vector<int> curr (m+1, 0); vector<int> prev (m+1, 0);

        f(i, n){
            f(j, m){
                if(word1[i-1] == word2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            prev = curr;
            curr = vector<int> (m+1, 0);
        }
        return n + m - 2*prev[m];
    }
};