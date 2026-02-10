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
    int maxSum = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;

        int leftSum = max(0, dfs(node->left));
        int rightSum = max(0, dfs(node->right));

        maxSum = max(maxSum, leftSum + rightSum + node->val);
        return max(node->val + max(leftSum, rightSum), node->val);
    }

    int maxPathSum(TreeNode* root) {
        int maxS = dfs(root);
        return maxSum;
    }
};