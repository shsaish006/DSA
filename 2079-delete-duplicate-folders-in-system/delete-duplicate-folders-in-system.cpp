struct TrieNode {
    unordered_map<string, shared_ptr<TrieNode>> children;
    bool deleted = false;
};

class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Sort paths to ensure insertion order is consistent
        sort(paths.begin(), paths.end());

        // Build the trie from all paths
        for (const auto& path : paths) {
            auto node = root;
            for (const string& folder : path) {
                if (!node->children.count(folder))
                    node->children[folder] = make_shared<TrieNode>();
                node = node->children[folder];
            }
        }

        // Map subtree serialization -> list of nodes with that structure
        unordered_map<string, vector<shared_ptr<TrieNode>>> subtreeMap;
        serialize(root, subtreeMap);

        // Mark all duplicate subtrees as deleted
        for (const auto& [_, nodes] : subtreeMap) {
            if (nodes.size() > 1) {
                for (auto& node : nodes)
                    node->deleted = true;
            }
        }

        // Reconstruct valid folder paths
        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);
        return result;
    }

private:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    // Recursively serialize subtrees and populate map
    string serialize(shared_ptr<TrieNode> node,
                     unordered_map<string, vector<shared_ptr<TrieNode>>>& subtreeMap) {
        string signature = "(";
        for (const auto& [folder, child] : node->children) {
            signature += folder + serialize(child, subtreeMap);
        }
        signature += ")";
        if (signature != "()") // Don't map empty folders
            subtreeMap[signature].push_back(node);
        return signature;
    }

    // Reconstruct folder paths from non-deleted nodes
    void collect(shared_ptr<TrieNode> node, vector<string>& path,
                 vector<vector<string>>& result) {
        for (const auto& [folder, child] : node->children) {
            if (!child->deleted) {
                path.push_back(folder);
                result.push_back(path);
                collect(child, path, result);
                path.pop_back();
            }
        }



        
    }
};




