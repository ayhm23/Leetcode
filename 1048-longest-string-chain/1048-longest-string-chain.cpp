class Solution {
public:

    bool isMatch(string &a, string &b){
        if(a.size() != b.size() + 1) return false;

        int i = 0, j = 0;
        while(j < b.size() && i < a.size()){
            if(a[i] == b[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }
        return j == b.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<string>& temp = words;
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        
        

        vector<int> dp (n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if((temp[i].size() == temp[j].size() + 1) && isMatch(temp[i], temp[j])){
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};