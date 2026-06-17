class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop(); k--;
            }

            st.push(num[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop(); k--;
        }

        if(st.empty()) return "0";

        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0')i++;

        return ans.substr(i).size() ? ans.substr(i) : "0";
    }
};