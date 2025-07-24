class Solution {
public:
    vector<vector<int>> tree;
    vector<int> in, out, subXor;
    int timer = 0;

    void dfs(int node, int parent, vector<int>& nums) {
        in[node] = ++timer;
        subXor[node] = nums[node];
        for (int nei : tree[node]) {
            if (nei != parent) {
                dfs(nei, node, nums);
                subXor[node] ^= subXor[nei];
            }
        }
        out[node] = ++timer;
    }

    bool isAncestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.resize(n);
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        in.resize(n);
        out.resize(n);
        subXor.resize(n);

        dfs(0, -1, nums);

        int totalXor = subXor[0];
        int minDiff = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a, b, c;

                if (isAncestor(i, j)) {
                    a = subXor[j];
                    b = subXor[i] ^ subXor[j];
                    c = totalXor ^ subXor[i];
                }
                else if (isAncestor(j, i)) {
                    a = subXor[i];
                    b = subXor[j] ^ subXor[i];
                    c = totalXor ^ subXor[j];
                }
                else {
                    a = subXor[i];
                    b = subXor[j];
                    c = totalXor ^ subXor[i] ^ subXor[j];
                }

                int currentMax = max({a, b, c});
                int currentMin = min({a, b, c});
                minDiff = min(minDiff, currentMax - currentMin);
            }
        }

        return minDiff;
    }
};
