class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        vector<int> ans;

        while (node || !st.empty()) {

            // go left as far as possible
            while (node) {
                st.push(node);
                node = node->left;
            }

            // visit node
            node = st.top();
            st.pop();

            ans.push_back(node->val);

            // move to right subtree
            node = node->right;
        }

        return ans;
    }
};