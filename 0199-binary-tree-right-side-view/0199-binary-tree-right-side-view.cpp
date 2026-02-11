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
        vector<int> ans;
        if(!root) return ans;

        queue<pair<TreeNode*, int>> q;
        map<int,int> nodes; 
        
        q.push({root, 0});
        while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode* node = it.first;
            int row = it.second;

            if(nodes.find(row) == nodes.end()){
                nodes[row] = node->val;
            }
            if(node->right) q.push({node->right, row + 1});
            if(node->left) q.push({node->left, row + 1});
        }
        for(auto &it : nodes){
            ans.push_back(it.second);
        }   
        return ans;
    }
};