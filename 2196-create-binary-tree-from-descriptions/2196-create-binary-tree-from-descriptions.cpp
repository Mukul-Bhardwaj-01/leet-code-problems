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
    void fun(TreeNode* root, unordered_map<int,vector<pair<int,int>>> &parentChild) {
        if(!root) return;

        auto it = parentChild.find(root -> val);
        if(it == parentChild.end()) return;
        auto children = it -> second;
        TreeNode* left_node = nullptr, * right_node = nullptr;
        for(auto &p : children) {
            if(p.second) {
                left_node = new TreeNode(p.first);
            }
            else {
                right_node = new TreeNode(p.first);
            }
        }
        root -> left = left_node;
        root -> right = right_node;

        fun(root -> left, parentChild);
        fun(root -> right, parentChild);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>> parentChild;
        unordered_map<int,int> nodeOccurance;
        for(auto &vec : descriptions) {
            parentChild[vec[0]].push_back({vec[1],vec[2]});
            nodeOccurance[vec[0]]++;
            nodeOccurance[vec[1]]+=3;
        }
        int a;
        for(auto &it : nodeOccurance) {
            if(it.second <= 2) {
                a = it.first;
                break;
            }
        }
        TreeNode* root = new TreeNode(a);
        fun(root,parentChild);
        return root;
    }
};