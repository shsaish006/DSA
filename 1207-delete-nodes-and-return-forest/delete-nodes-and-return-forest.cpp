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
private: 
    TreeNode* processNode(TreeNode* node, unordered_set<int>& toDelSet, vector<TreeNode*>& forest) {
        if(!node) {
            return NULL;
        }
        node->left = processNode(node->left, toDelSet, forest);
        node->right  = processNode(node->right, toDelSet, forest);
        if(toDelSet.find(node->val) != toDelSet.end()) {
            if(node->left) {
                forest.push_back(node->left);
            }
            if(node->right) {
                forest.push_back(node->right);
            }
            delete node;
            return NULL;
        }
        return node;
    }


public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        root = processNode(root, toDelSet, forest);

        if(root) {
            forest.push_back(root);
        }

        return forest;
    }
};
/**class Solution {
public:
TreeNode* deleteHelper(TreeNode* root,unordered_set<int>& st,vector<TreeNode*>& result ){
    if(root==NULL)
    return NULL;
    root->left=deleteHelper(root->left,st,result);
    root->right=deleteHelper(root->right,st,result);
    if(st.find(root->val)!=st.end()){
        if(root->left!=NULL)
        result.push_back(root->left);
        if(root->right!=NULL)
        result.push_back(root->right);

        return NULL;
    }else{
        return root;
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>result;
        unordered_set<int> st;
        for(int &num:to_delete){
            st.insert(num);
        }
        deleteHelper(root,st,result);
        if(st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
        
    }
};*/
