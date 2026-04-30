/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        unordered_map<TreeNode*, TreeNode*> childParent;
        childParent[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) {
                    q.push(node -> left);
                    childParent[node -> left] = node;
                }
                if(node -> right) {
                    q.push(node -> right);
                    childParent[node -> right] = node;
                }
            }
        }
        unordered_set<TreeNode*> visited;
        int dis = 0;
        q.push(target);
        visited.insert(target);
        while(!q.empty()) {
            if(dis == k) break;
            int size = q.size();
            for(int i = 0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if(childParent[node] && !visited.count(childParent[node])) {
                    q.push(childParent[node]);
                    visited.insert(childParent[node]);
                }
                if(node -> left && !visited.count(node -> left)) {
                    q.push(node -> left);
                    visited.insert(node -> left);
                }
                if(node -> right && !visited.count(node -> right)) {
                    q.push(node -> right);
                    visited.insert(node -> right);
                }
            }
            dis++;
        }
        while(!q.empty()) {
            ans.push_back(q.front() -> val);
            q.pop();
        }
        return ans;
    }
};