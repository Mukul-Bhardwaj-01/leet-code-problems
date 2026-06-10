class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        unordered_set<int> trim_len;
        for(auto &query : queries) {
            trim_len.insert(query[1]);
        }

        unordered_map<int, vector<pair<string,int>>> postTrim;

        for(int trim : trim_len) {
            vector<pair<string,int>> v;

            for(int i = 0; i < nums.size(); ++i) {
                string trimmed = nums[i].substr(nums[i].size() - trim);
                v.push_back({trimmed, i});
            }

            sort(v.begin(), v.end());

            postTrim[trim] = v;
        }

        for(auto &query : queries) {
            int k = query[0];
            int trim = query[1];

            ans.push_back(postTrim[trim][k - 1].second);
        }

        return ans;
    }
};