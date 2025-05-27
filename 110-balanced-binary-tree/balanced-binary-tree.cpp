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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left),level(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left=level(root->left);
        int right=level(root->right);
        int d=left-right;
        if(d<0) d=-1*d;
        if(d<2) return isBalanced(root->left)&& isBalanced(root->right);
        return false;
    }
};