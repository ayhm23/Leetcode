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
    void dfs(TreeNode* Node, int curr, int &maxx){
        if(!Node) return;
        maxx = max(maxx, curr);
        dfs(Node->left, curr + 1, maxx);
        dfs(Node->right, curr + 1, maxx);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int curr = 1, maxx = 1;
        dfs(root, curr, maxx);
        return maxx;
    }
};