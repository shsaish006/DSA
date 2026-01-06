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
    void dfs(TreeNode* root, int lvl, vector<long long>& vals) {
        if (!root) return;
        if (lvl == vals.size()) vals.push_back(0);
        vals[lvl] += root->val;
        dfs(root->left, lvl + 1, vals);
        dfs(root->right, lvl + 1, vals);
    }
    
    int maxLevelSum(TreeNode* root) {
        vector<long long> vals;
        dfs(root, 0, vals);
        long long mx = LLONG_MIN;
        int ans = 0;
        for (int i = 0; i < vals.size(); i++) {
            if (vals[i] > mx) {
                mx = vals[i];
                ans = i + 1;
            }
        }
        return ans;
    }
};