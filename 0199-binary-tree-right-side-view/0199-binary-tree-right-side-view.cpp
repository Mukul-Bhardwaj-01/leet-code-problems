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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<int, TreeNode*>> q;
        map<int,int> rightSide;
        q.push({0, root});
        while(!q.empty()) {
            auto a = q.front();
            q.pop();
            int level = a.first;
            TreeNode* node = a.second;
            rightSide[level] = node -> val;
            if(node -> left) q.push({level + 1, node -> left});
            if(node -> right) q.push({level + 1, node -> right});
        }
        vector<int> ans;
        for(auto it : rightSide) ans.push_back(it.second);
        return ans;
    }
};