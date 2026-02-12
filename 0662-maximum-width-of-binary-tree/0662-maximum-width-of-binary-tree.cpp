class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (!root) return 0;

        long long maxx = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            long long sz = q.size();
            long long base = q.front().second;   // normalize
            long long first = 0, last = 0;

            for (long long i = 0; i < sz; i++) {
                auto it = q.front(); 
                q.pop();

                TreeNode* node = it.first;
                long long idx = it.second - base;  // normalize here

                if (i == 0) first = idx;
                if (i == sz - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            maxx = max(maxx, last - first + 1);
        }

        return (int)maxx;
    }
};
