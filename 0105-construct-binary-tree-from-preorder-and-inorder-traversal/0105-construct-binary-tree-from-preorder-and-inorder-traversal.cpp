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
    TreeNode * buildingTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int,int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode * parent = new TreeNode(preorder[preStart]);
        int inParent = inMap[preorder[preStart]];
        int numsLeft = inParent - inStart;

        parent -> left = buildingTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inParent - 1, inMap);
        parent -> right = buildingTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inParent + 1, inEnd, inMap);

        return parent;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for(int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }
        TreeNode * root = buildingTree(preorder, 0, preorder.size()-1,
                                        inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};