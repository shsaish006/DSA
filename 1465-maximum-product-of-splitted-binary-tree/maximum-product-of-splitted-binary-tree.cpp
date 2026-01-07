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
    long long s=0,ans=0;
    long long f(TreeNode* r){
        return r?r->val+f(r->left)+f(r->right):0;
    }
    long long g(TreeNode* r){
        if(!r) return 0;
        long long t=r->val+g(r->left)+g(r->right);
        ans=max(ans,t*(s-t));
        return t;
    }
    int maxProduct(TreeNode* r) {
        s=f(r);
        g(r);
        return ans%1000000007;
    }
};