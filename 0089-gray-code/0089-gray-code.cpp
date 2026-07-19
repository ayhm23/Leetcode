class Solution {
public:
    bool BackTrack(vector<int>& curr, int n, unordered_set<int>& vis) {
        if (curr.size() == (1 << n))
            return true;

        int last = curr.back();

        for (int i = 0; i < n; i++) {
            int next = last ^ (1 << i);

            if (!vis.count(next)) {
                curr.push_back(next);
                vis.insert(next);

                if (BackTrack(curr, n, vis))
                    return true;

                curr.pop_back();
                vis.erase(next);
            }
        }

        return false;
    }

    vector<int> grayCode(int n) {
        vector<int> curr = {0};
        unordered_set<int> vis;
        vis.insert(0);

        BackTrack(curr, n, vis);
        return curr;
    }
};