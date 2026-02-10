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
    // void inorder(TreeNode* root, vector<int> & ans){
    //     if(!root) return;

    //     inorder(root->left, ans);
    //     ans.push_back(root->val);
    //     inorder(root->right, ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root, ans);
    //     return ans;
    // }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
            // go to the leftmost node
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            // move to right subtree
            curr = curr->right;
        }

        return ans;
    }
};