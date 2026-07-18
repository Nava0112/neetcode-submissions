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
vector<int>ans;
public:
    void func(int i, TreeNode* root){
        if(!root) return;
        if(ans.size()==i){
            ans.push_back(root->val);
        }
        func(i+1, root->right);
        func(i+1, root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        func(0,root);
        return ans;
    }
};
