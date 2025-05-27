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
    set<int>nodeSet;
    void countNode(TreeNode* root){
        if(root==NULL)
        return;
        nodeSet.insert(root->val);
        countNode(root->left);
        countNode(root->right);
        return;
    }
    bool isUnivalTree(TreeNode* root) {
        countNode(root);
        if(nodeSet.size()>1)
        return false;
        return true;
        
    }
};