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
    void preOrder(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL) return;
        ans[level]=root->val;
        preOrder(root->left,ans,level+1);
        preOrder(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n=level(root);
        vector<int> ans(n,0);
        preOrder(root,ans,0);
        return ans;        
    }
};