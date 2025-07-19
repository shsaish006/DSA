class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    bool isEnd = false;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();

        auto split = [](const string& path) {
            vector<string> parts;
            stringstream ss(path);
            string segment;
            while (getline(ss, segment, '/')) {
                if (!segment.empty())
                    parts.push_back(segment);
            }
            return parts;
        };

        for (const string& f : folder) {
            TrieNode* node = root;
            auto parts = split(f);
            bool skip = false;
            for (const string& part : parts) {
                if (node->isEnd) {
                    skip = true;
                    break;
                }
                if (!node->children.count(part))
                    node->children[part] = new TrieNode();
                node = node->children[part];
            }
            if (!skip) node->isEnd = true;
        }

        vector<string> result;
        function<void(TrieNode*, string)> dfs = [&](TrieNode* node, string path) {
            if (node->isEnd) {
                result.push_back(path);
                return;
            }
            for (auto& [name, child] : node->children) {
                dfs(child, path + "/" + name);
            }
        };

        dfs(root, "");
        return result;
    }
};
