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
    vector<int> rightSideView(TreeNode* root) {
        //similar to level order but bottom view ans use rows
        vector<int> ans; if(!root) return ans;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        map<int, int> mp;

        while(!q.empty()){
            auto [node, row] = q.front(); q.pop();
            mp[row] = node->val;
            if(node->left) q.push({node->left, row+1});
            if(node->right) q.push({node->right, row+1});
        }

        for(auto &[row, val] : mp) ans.push_back(val);
        return ans;
    }
};