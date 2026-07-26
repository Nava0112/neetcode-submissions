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
private:
int ans = INT_MIN;
public:
    int func(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l = func(root->left);
        int r = func(root->right);
        if(l<0 && r<0) {
            ans = max(ans, root->val);
            return root->val;
        }
        if(l<0) {
            ans = max(ans , root->val + r);
            return root->val + r;
        }
        if(r<0) {
            ans = max( ans , root->val + l);
            return root->val + l;
        }
        ans = max(ans, root->val + l + r);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return ans;
    }
};
