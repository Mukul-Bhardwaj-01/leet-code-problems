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
        stack<pair<TreeNode*,pair<int,int>>> st;
        map<int, map<int, multiset<int>>> helperMap;
        st.push({root, {0,0}});
        while(!st.empty()) {
            auto temp = st.top();
            st.pop();
            TreeNode* node = temp.first;
            int x = temp.second.first, y = temp.second.second;
            helperMap[x][y].insert(node -> val);
            if(node -> right != nullptr) {
                st.push({node -> right, {x + 1, y + 1}});
            }
            if(node -> left != nullptr) {
                st.push({node -> left, {x - 1, y + 1}});
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