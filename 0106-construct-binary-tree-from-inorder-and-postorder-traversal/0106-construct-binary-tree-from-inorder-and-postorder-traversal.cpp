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
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode * build(vector<int>&postorder, vector<int>&inorder, int left, int right){
        if(right < left) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode * root = new TreeNode(rootVal);

        int inIndex = mp[rootVal];

        root->right = build(postorder, inorder, inIndex + 1, right);
        root->left = build(postorder, inorder, left, inIndex - 1);
        
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i; //store index of inorder elements
        }

        return build(postorder, inorder, 0, inorder.size()-1);
    }
};