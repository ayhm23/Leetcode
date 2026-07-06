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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans; if(!root) return ans;
    //     stack<TreeNode*> st1, st2;
    //     st1.push(root);

    //     while(!st1.empty()){
    //         auto it = st1.top(); st1.pop();
    //         st2.push(it);
    //         if(it->left) st1.push(it->left);
    //         if(it->right) st1.push(it->right);
    //     }

    //     while(!st2.empty()){
    //         ans.push_back(st2.top()->val);
    //         st2.pop();
    //     }
    //     return ans;
    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; if(!root) return ans;
        stack<TreeNode*> st; 
        TreeNode* cur = root, *last = NULL;

        while(cur || !st.empty()){
            if(cur){
                st.push(cur); cur = cur->left;
            }
            else{
                TreeNode * peek = st.top();
                if(peek->right && last != peek->right){
                    cur = peek->right;
                }
                else{
                    ans.push_back(peek->val);
                    last = peek; st.pop();
                }
            }
        }
        return ans;
    }
};