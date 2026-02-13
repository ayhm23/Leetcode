/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root || !target) return ans;
        
        
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        queue<pair<TreeNode*, int>> q;
        q.push({root,0});


        while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode* node = it.first; int l = it.second;
            if(node->left){
                parent[node->left] = node;
                q.push({node->left, l+1});
            }
            if(node->right){
                parent[node->right] = node;
                q.push({node->right, l+1});
            }
        }

        q.push({target, 0});
        unordered_map <int,int> vis;
        vis[target->val] = 1;

        while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode * node = it.first; int dist = it.second;

            if(dist == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left && vis.find(node->left->val) == vis.end()){
                q.push({node->left, dist+1});
                vis[node->left->val] = 1;

            }
            if(node->right && vis.find(node->right->val) == vis.end()){
                q.push({node->right, dist+1});
                vis[node->right->val] = 1;

            }
            if(parent[node] && vis.find(parent[node]->val) == vis.end()){
                q.push({parent[node], dist+1});
                vis[parent[node]->val] = 1;
            }
        }
        return ans;
    }
};