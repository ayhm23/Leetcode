class Solution {
public:
    int minLength(string s) {
        //kinda like valid parenthesis -- use stack
        stack<char> st;

        for(char& c : s){
            if(!st.empty() && ((c == 'B' && st.top() == 'A') || (c == 'D' && st.top() == 'C'))){
                st.pop(); continue;
            }
            st.push(c);
        }
        return st.size();
    }
};