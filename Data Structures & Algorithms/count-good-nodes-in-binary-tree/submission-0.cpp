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
int cnt = 0;
public:
    void func(int h, TreeNode* root){
        if(!root) return;
        if(root->val>=h){
            cnt++;
            h = root->val;
        }
        func(h, root->left);
        func(h, root->right); 
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        func(INT_MIN, root);
        return cnt;
    }
};
