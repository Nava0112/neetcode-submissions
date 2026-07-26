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

//low - inordere
//root- preorder
class Solution {
public:
    TreeNode* rec(vector<int>&preorder, int pst, int pnd, vector<int> &inorder, int ist, int ind){
        if(pst > pnd){
            return nullptr;
        }
        int i=ist;
        for(i; i<ind; i++){
            if(inorder[i]==preorder[pst]) break;
        }
        int leftSize = i - ist;
        TreeNode* dum = new TreeNode(preorder[pst]);
        dum -> left = rec(preorder,pst+1, pst+leftSize,  inorder, ist, i-1);
        dum -> right = rec(preorder,pst+leftSize+1, pnd, inorder, i+1, ind);
        return dum;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return rec(preorder, 0, n-1, inorder, 0, n-1);
    }
};
