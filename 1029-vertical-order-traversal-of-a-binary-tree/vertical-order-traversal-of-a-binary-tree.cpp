// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
class Solution {
    void dfs(TreeNode* root, int row, int col,
             map<int, vector<pair<int, int>>>& mp) {
        if (!root)
            return;
        mp[col].push_back({row, root->val});
        if (root->left)
            dfs(root->left, row + 1, col - 1, mp);
        if (root->right)
            dfs(root->right, row + 1, col + 1, mp);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> mp;
        dfs(root, 0, 0, mp);
        for (auto& it : mp) {
            auto& vec = it.second;
            // sort(vec.begin(),vec.end(),[](auto & a, auto &b){
            //     if(a.first==b.first)
            //     return a.first<b.second;
            //     return a.first<b.first;
            // });
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> cv;
            for (auto& p : vec)
                cv.push_back(p.second);
            ans.push_back(cv);
        }
        return ans;
    }
};
//  Soln 2
// class Solution {
//     void dfs(TreeNode* root, int row, int col,
//              map<int, map<int, multiset<int>>> &mp) {
        
//         if (!root) return;

//         mp[col][row].insert(root->val);

//         dfs(root->left, row + 1, col - 1, mp);
//         dfs(root->right, row + 1, col + 1, mp);
//     }

// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//         map<int, map<int, multiset<int>>> mp;
//         dfs(root, 0, 0, mp);

//         vector<vector<int>> ans;

//         for (auto &colPair : mp) {
//             vector<int> column;

//             for (auto &rowPair : colPair.second) {
//                 for (int val : rowPair.second) {
//                     column.push_back(val);
//                 }
//             }

//             ans.push_back(column);
//         }

//         return ans;
//     }
// };