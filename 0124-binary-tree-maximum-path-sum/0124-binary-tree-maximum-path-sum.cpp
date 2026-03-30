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
    int dfsSumPath(TreeNode* root, int& maxSum) {
        if(root == nullptr) return 0;
        int leftSum = dfsSumPath(root -> left, maxSum);
        int rightSum = dfsSumPath(root -> right, maxSum);
        if(leftSum < 0) leftSum = 0;
        if(rightSum < 0) rightSum = 0; 
        maxSum = max(maxSum, root->val + leftSum + rightSum);
        return root -> val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = root -> val;
        dfsSumPath(root, maxSum);
        return maxSum;
    }
};