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
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty()) {
            int size = q1.size();
            for(int i = 0; i<size; ++i) {
                TreeNode* node = q1.front();
                q1.pop();
                if(node -> left) {
                    q1.push(node -> left);
                    childParent[node -> left] = node;
                }
                if(node -> right) {
                    q1.push(node -> right);
                    childParent[node -> right] = node;
                }
            }
        }
        unordered_set<TreeNode*> visited;
        int dis = 0;
        q2.push(target);
        visited.insert(target);
        while(!q2.empty()) {
            if(dis == k) break;
            int size = q2.size();
            for(int i = 0; i<size; ++i) {
                TreeNode* node = q2.front();
                q2.pop();
                if(childParent[node] && !visited.count(childParent[node])) {
                    q2.push(childParent[node]);
                    visited.insert(childParent[node]);
                }
                if(node -> left && !visited.count(node -> left)) {
                    q2.push(node -> left);
                    visited.insert(node -> left);
                }
                if(node -> right && !visited.count(node -> right)) {
                    q2.push(node -> right);
                    visited.insert(node -> right);
                }
            }
            dis++;
        }
        while(!q2.empty()) {
            ans.push_back(q2.front() -> val);
            q2.pop();
        }
        return ans;
    }
};