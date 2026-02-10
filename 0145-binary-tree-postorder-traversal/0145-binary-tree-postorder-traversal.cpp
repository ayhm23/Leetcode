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

// class Solution {
// public:
//     void postOrder(TreeNode* root, vector<int> & ans){
//         if(!root) return;

//         postOrder(root->left, ans);
//         postOrder(root->right, ans);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         postOrder(root, ans);
//         return ans;
//     }
// };


//Iterative 2 stack
// class Solution {
// public:
    
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;

//         stack<TreeNode*> st1;
//         stack<int> st2;

//         st1.push(root);

//         while(!st1.empty()){
//             TreeNode * curr = st1.top();
//             st1.pop();
//             st2.push(curr->val);

//             if(curr->left) st1.push(curr->left);
//             if(curr->right) st1.push(curr->right);
//         }

//         while(!st2.empty()){
//             ans.push_back(st2.top());
//             st2.pop();
//         }
//         return ans;
//     }
// };

//iterative 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = st.top();
                if (node->right != nullptr && lastVisited != node->right) {
                    curr = node->right;
                } else {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};