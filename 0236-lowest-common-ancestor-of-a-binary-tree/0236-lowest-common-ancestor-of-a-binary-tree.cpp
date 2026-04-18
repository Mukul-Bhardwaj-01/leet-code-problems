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
    bool getPath(TreeNode* node, vector<TreeNode*>& path, TreeNode* targetNode) {
        if(!node) return false;
        path.push_back(node);

        if(node == targetNode) return true;
        if(getPath(node -> left, path, targetNode)||getPath(node -> right, path, targetNode))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        getPath(root, path1, p);
        getPath(root, path2, q);
        int i = 1;
        TreeNode* ans = root;
        while(i<(path1.size()>=path2.size()?path2.size():path1.size()) && path1[i] == path2[i]) {
            ans = path1[i];
            i++;
        }
        return ans;
    }
};