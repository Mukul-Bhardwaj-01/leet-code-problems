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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        bool flag = 1;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node -> val);
                if(node -> left != nullptr) q.push(node -> left);
                if(node -> right != nullptr) q.push(node -> right);
            }
            if(!flag) reverse(level.begin(),level.end());
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};