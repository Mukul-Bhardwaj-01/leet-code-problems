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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int, map<int, multiset<int>>> helperMap;
        q.push({root, {0,0}});
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first, y = temp.second.second;
            helperMap[x][y].insert(node -> val);
            if(node -> left != nullptr) {
                q.push({node -> left, {x - 1, y + 1}});
            }
            if(node -> right != nullptr) {
                q.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto a : helperMap) {
            vector<int> ansPart;
            for(auto b : a.second)
                ansPart.insert(ansPart.end(),b.second.begin(),b.second.end());
            ans.push_back(ansPart);
        }
        return ans;
    }
};