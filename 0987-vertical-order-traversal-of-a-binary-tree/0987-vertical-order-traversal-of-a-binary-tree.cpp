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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //in queue we put node - level - x col
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<TreeNode * ,pair<int,int>>> q;
        map<int, map<int, multiset<int>>> nodes;

        //level order traversal

        //map - map - multiset helps sorting by coloumn -> row -> value

        q.push({root, {0,0}});

        while(!q.empty()){
            auto it = q.front(); q.pop();
            TreeNode * node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(node->left){
                q.push({node->left, {x - 1, y + 1}});
            }
            if(node->right){
                q.push({node->right, {x + 1, y + 1}});
            }
            nodes[x][y].insert(node->val);
        }

        for(auto &col : nodes){
            vector<int> temp;
            for(auto &row : col.second){
                temp.insert(temp.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};