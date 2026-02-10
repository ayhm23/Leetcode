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
    int diameter = 0;

    int height(TreeNode * Node){
        if(!Node) return 0;

        int ld = height(Node->left);

        int rd = height(Node->right);

        diameter = max(ld + rd, diameter);

        return 1 + max(ld,rd);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int hg = height(root);
        return diameter;
    }   
};