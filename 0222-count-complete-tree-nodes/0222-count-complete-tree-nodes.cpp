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
    int i = 0;
    void bfs(TreeNode* node) {
        if(!node) return;
        i++;
        if(node -> left) bfs(node -> left);
        if(node -> right) bfs(node -> right);
    }
    int countNodes(TreeNode* root) {
        bfs(root);
        return i;
    }
};