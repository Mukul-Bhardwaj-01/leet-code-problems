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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * node = new TreeNode(val);
        if(!root) return node;
        TreeNode* curr = root;
        while(curr) {
            if(curr -> val > val && !curr -> left) {
                curr -> left = node;
                break;
            }
            else if(curr -> val > val) curr = curr -> left;
            else if(curr -> val < val && !curr -> right) {
                curr -> right = node;
                break;
            }
            else curr = curr -> right;
        }
        return root;
    }
};