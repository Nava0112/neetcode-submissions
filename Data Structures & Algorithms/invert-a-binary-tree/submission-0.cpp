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
    TreeNode* func(TreeNode* root){
        if(root==nullptr) return nullptr;
        TreeNode* l = (root->left)?root->left:nullptr; 
        TreeNode* r = (root->right)?root->right:nullptr;
        root->right = l;
        root->left = r;
        func(root->left);
        func(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return func(root);
    }
};
