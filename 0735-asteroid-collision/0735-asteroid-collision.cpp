class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool alive = true;

            // collision only when stack top is +ve and curr is -ve
            while (!st.empty() && st.top() > 0 && curr < 0) {

                if (abs(st.top()) < abs(curr)) {
                    // stack asteroid explodes
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(curr)) {
                    // both explode
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    // current explodes
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(curr);
            }
        }

        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
