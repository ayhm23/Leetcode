class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int x : asteroids) {
            bool alive = true;

            while (alive && x < 0 && !st.empty() && st.top() > 0) {
                if (st.top() < -x) {
                    st.pop();              // positive asteroid explodes
                } else if (st.top() == -x) {
                    st.pop();              // both explode
                    alive = false;
                } else {
                    alive = false;         // current negative explodes
                }
            }

            if (alive)
                st.push(x);
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};