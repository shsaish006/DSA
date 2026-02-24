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
    int sumRootToLeaf(TreeNode* root) {
        unordered_map<TreeNode*,int> dp;
        return dfs(root,0,dp);
        
    }
    int dfs(TreeNode* node, int ps, unordered_map<TreeNode*,int>&dp){
        if(!node) return 0;
        ps=(ps<<1)|node->val;
        if(dp.count(node)) return dp[node];
        if(!node->left && !node->right){
            dp[node]=ps;
            return dp[node];
        }
        dp[node]=dfs(node->left,ps,dp)+dfs(node->right,ps,dp);
        return dp[node];
    }
};