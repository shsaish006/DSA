/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void solve(Node* root,vector<int>&ans){
    for(Node*x:root->children){
        solve(x,ans);

    }
    ans.push_back(root->val);
}
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        solve(root,ans);
        return ans;
        
    }
};