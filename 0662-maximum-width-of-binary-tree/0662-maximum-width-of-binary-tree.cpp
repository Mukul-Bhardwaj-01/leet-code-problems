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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty()) {
            int size = q.size();
            long long minId = q.front().second;
            long long first, last;
            for(int i = 0; i<size; ++i) {
                long long cur_Id = q.front().second - minId;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = cur_Id;
                if(i == size - 1) last = cur_Id;
                if(node -> left) q.push({node -> left, 2*cur_Id + 1});
                if(node -> right) q.push({node -> right, 2*cur_Id + 2});
            }
            ans = max(ans,(int)(last - first + 1));
        }
        return ans;
    }
};