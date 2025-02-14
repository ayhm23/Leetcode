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
    void InOrderTraversal(TreeNode * root, vector<int> &arr){
        if(!root) return;
        InOrderTraversal(root->left, arr);
        arr.push_back(root->val);
        InOrderTraversal(root->right, arr);
    }

    TreeNode* arrange(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  // Corrected base case

        int mid = left + (right - left) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);  // Create new node
        root->left = arrange(nums, left, mid - 1);  // Corrected mid index for left subtree
        root->right = arrange(nums, mid + 1, right); // Recursively create right subtree
        
        return root;  // Return the root of this subtree
    }


    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedArr;
        InOrderTraversal(root, sortedArr);
        return arrange(sortedArr, 0, sortedArr.size()-1);
    }
};