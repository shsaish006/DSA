/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
//  node=n
    Node* cloneGraph(Node* n) {
        unordered_map<Node*,Node*>mp;
        auto f=[&](this auto&& f, Node*n)->Node*{
            if(!n) return nullptr;
            if(mp.count(n)) return mp[n];
            mp[n]=new Node(n->val);
            for(auto x: n->neighbors)
            mp[n]->neighbors.push_back(f(x));
        return mp[n];
        };
        return f(n);


        
    }
};
//  agar node null hain to we have to return null phir hum hashmap maintain karenge phir dfs agar current node mp mein hain to return karenge hum cloned nhi to new node banayenge same value ke saath and store karnege mp mein and visit karenge neighbor recursively and add karnege cloned neighbor to cloned node mein list and return karenge cloned node directly proprotional to jaha se sgtart kiya tha. Tc  0(V+E) 