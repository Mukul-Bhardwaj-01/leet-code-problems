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
    bool exists(int key, TreeNode* root) {
        while(root) {
            if(root -> val == key) return true;
            else if(root -> val > key) root = root -> left;
            else root = root -> right;
        }
        return false;
    }
    TreeNode * rightMostNode(TreeNode* node) {
        while(node -> right) {
            node = node -> right;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(!root -> left && !root -> right && root -> val == key) return nullptr;
        if(!root -> left && !root -> right) return root;
        if(!exists(key, root)) return root;

        if(root -> val == key) { // If the root is to be deleted
            if(root -> left == nullptr) return root -> right;
            if(root -> right == nullptr) return root -> left;
            TreeNode* rightmost = rightMostNode(root -> left);
            rightmost -> right = root -> right;
            return root -> left;
        }
        TreeNode* curr = root;
        while(curr) {
            if(curr -> val > key) {
                if(curr -> left -> val == key) {
                    if(!curr -> left -> left) {
                        curr -> left = curr -> left -> right;
                        break;
                    }
                    if(!curr -> left -> right) {
                        curr -> left = curr -> left -> left;
                        break;
                    }
                    TreeNode* temp = curr -> left -> right;
                    curr -> left = curr -> left -> left;
                    TreeNode* rightmost = rightMostNode(curr -> left);
                    rightmost -> right = temp;
                    break;
                }
                else {
                    curr = curr -> left;
                }
            }
            else {
                if(curr -> right -> val == key) {
                    if(!curr -> right -> left) {
                        curr -> right = curr -> right -> right;
                        break;
                    }
                    if(!curr -> right -> right) {
                        curr -> right = curr -> right -> left;
                        break;
                    }
                    TreeNode* temp = curr -> right -> right;
                    curr -> right = curr -> right -> left;
                    TreeNode* rightmost = rightMostNode(curr -> right);
                    rightmost -> right = temp;
                    break;
                }
                else {
                    curr = curr -> right;
                }
            }
        }
        return root;
    }
};