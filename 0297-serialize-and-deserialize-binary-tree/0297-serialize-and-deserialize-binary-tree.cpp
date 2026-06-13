/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr) {
                ans << "#,";
                continue;
            }
            ans << node -> val << ",";
            q.push(node -> left);
            q.push(node -> right);
        }
        return ans.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        int i = 0, j = 0;
        while(j < data.length()) {
            if(data[j] == ',') {
                nodes.push_back(data.substr(i,j-i));
                i = j+1;
            }
            j++;
        }

        int n = nodes.size();
        if(n == 0 || nodes[0] == "#") return nullptr;

        queue<TreeNode*> q;
        TreeNode * root = new TreeNode(stoi(nodes[0]));
        q.push(root);
        i = 1;
        while(!q.empty() && i < n) {
            TreeNode * node = q.front();
            q.pop();
            TreeNode * left = nullptr;
            TreeNode * right = nullptr;

            if(i < n && nodes[i] != "#") left = new TreeNode(stoi(nodes[i]));
            i++;

            if(i < n && nodes[i] != "#") right = new TreeNode(stoi(nodes[i]));
            i++;

            node -> left = left;
            node -> right = right;
            if(node -> left) q.push(left);
            if(node -> right) q.push(right);
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));