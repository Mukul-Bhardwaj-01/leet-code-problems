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
public:
    void dfs(TreeNode* node, queue<TreeNode*> &q) {
        if(!node) return;
        q.push(node);
        if(node -> left) dfs(node -> left, q);
        if(node -> right) dfs(node -> right, q);
        return;
    }
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        dfs(root,q);
        TreeNode* prev = root;
        q.pop();
        while(prev != nullptr) {
            prev -> left = nullptr;
            if(!q.empty()) {
                prev -> right = q.front();
                q.pop();
            }
            else {
                prev -> right = nullptr;
            }
            prev = prev -> right;
        }
    }
};