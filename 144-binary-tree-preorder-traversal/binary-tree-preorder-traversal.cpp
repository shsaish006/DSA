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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int> ans;
        if(root==NULL) return ans;
        s.push(root);
        while(s.size()){
            auto a=s.top();
            s.pop();
            ans.push_back(a->val);
            if(a->right)s.push(a->right);
            if(a->left)s.push(a->left);
        }
        return ans;
        
    }
};