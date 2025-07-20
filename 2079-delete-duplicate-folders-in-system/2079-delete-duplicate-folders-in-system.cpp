class Solution {
    struct Trie {
        unordered_map<string, Trie*> children;
        string serial;
        bool deleted = false;
    };

    Trie* root = new Trie();
    unordered_map<string, int> serialCount;

    // Step 1: Build Trie from paths
    void insert(vector<string>& path) {
        Trie* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new Trie();
            }
            node = node->children[folder];
        }
    }

    // Step 2: Serialize each subtree
    string dfs_serialize(Trie* node) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.emplace_back(name, dfs_serialize(child));
        }

        sort(serials.begin(), serials.end());
        string serial;
        for (auto& [name, sub] : serials) {
            serial += "(" + name + sub + ")";
        }

        node->serial = serial;
        serialCount[serial]++;
        return serial;
    }

    // Step 3: Mark duplicate subtrees for deletion
    void dfs_mark(Trie* node) {
        if (serialCount[node->serial] > 1) {
            node->deleted = true;
        }

        for (auto& [_, child] : node->children) {
            dfs_mark(child);
        }
    }

    // Step 4: Collect valid (non-deleted) folder paths
    void dfs_collect(Trie* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->deleted) {
                path.push_back(name);
                res.push_back(path);
                dfs_collect(child, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Step 1
        for (auto& path : paths) insert(path);

        // Step 2
        dfs_serialize(root);

        // Step 3
        dfs_mark(root);

        // Step 4
        vector<vector<string>> res;
        vector<string> path;
        dfs_collect(root, path, res);
        return res;
    }
};
