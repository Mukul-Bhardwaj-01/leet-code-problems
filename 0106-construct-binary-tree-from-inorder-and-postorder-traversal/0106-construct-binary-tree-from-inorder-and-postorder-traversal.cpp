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
    TreeNode* buildingTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int,int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode * parent = new TreeNode(postorder[postEnd]);
        int inParent = inMap[parent -> val];
        int leftNums = inParent - inStart;

        parent -> left = buildingTree(inorder, inStart, inParent - 1, postorder, postStart, postStart + leftNums - 1, inMap);
        parent -> right = buildingTree(inorder, inParent + 1, inEnd, postorder, postStart + leftNums, postEnd - 1, inMap);

        return parent;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        TreeNode * root = buildingTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
        return root;
    }
};