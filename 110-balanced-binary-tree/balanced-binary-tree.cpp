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
    int h(TreeNode* a) {
        if (!a) return 0;
        int b = h(a->left);
        if (b == -1) return -1;
        int c = h(a->right);
        if (c == -1) return -1;
        if (abs(b - c) > 1) return -1;
        return 1 + max(b, c);
    }

    bool isBalanced(TreeNode* root) {
        return h(root) != -1;
    }
};