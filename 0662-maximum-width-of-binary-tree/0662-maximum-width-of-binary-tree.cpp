/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long maxx = 0;
        queue<pair<TreeNode*, long long>> q; // node , index
        q.push({root, 1});

        while (!q.empty()) {
            int sz = q.size();
            long long first = 0, last = 0;
            long long minIndex = q.front().second; // normalize

            for (int i = 0; i < sz; i++) {
                auto it = q.front(); q.pop();
                TreeNode* node = it.first;
                long long idx = it.second - minIndex;

                if (i == 0) first = idx;
                if (i == sz - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            maxx = max(maxx, last - first + 1);
        }

        return maxx;
    }
};
