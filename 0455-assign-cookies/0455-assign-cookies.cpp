class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end()), greater<int>());

        int ans = 0, i = 0;

        for(int child : g){
            if(i >= s.size()) break;
            if(child <= s[i]){
                i++;
                ans++;
            }
        }
        return ans;
    }
};