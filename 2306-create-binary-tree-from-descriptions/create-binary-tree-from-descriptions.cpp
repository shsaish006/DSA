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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> s;
        for (auto &x : d) {
            int p = x[0], c = x[1], l = x[2];
            if (!m.count(p)) m[p] = new TreeNode(p);
            if (!m.count(c)) m[c] = new TreeNode(c);
            l ? m[p]->left = m[c] : m[p]->right = m[c];
            s.insert(c);
        }
        for (auto &x : d)
            if (!s.count(x[0])) return m[x[0]];

        return nullptr;
    }
};