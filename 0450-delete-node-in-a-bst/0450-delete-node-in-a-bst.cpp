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
    TreeNode* helper(TreeNode*  node){
        while(node->left) node = node->left;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else{ // found the node to delete
            if(!root->left && !root->right) return nullptr;
            else if(root->left && root->right){ //main case
                TreeNode* small = helper(root->right);
                small->left = root->left;
                return root->right;
            }
            else{
                return root->left ? root->left : root->right;
            }
        }
        return root;
    }
};