class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> vecInd;
        int n = arr.size();
        if(n == 0) return {};
        for(int i = 0; i < n; ++i) {
            vecInd.push_back({arr[i],i});
        }
        sort(vecInd.begin(),vecInd.end());

        vector<pair<int,int>> ansInd;
        ansInd.push_back({1,vecInd[0].second});
        int rank = 1;
        int i = 1;
        while(i < n) {
            if(vecInd[i].first == vecInd[i - 1].first) {
                ansInd.push_back({rank,vecInd[i].second});
            }
            else {
                rank++;
                ansInd.push_back({rank,vecInd[i].second});
            }
            i++;
        }

        sort(ansInd.begin(),ansInd.end(), [] (const auto &a, const auto &b) {
            return a.second < b.second;
        });

        vector<int> ans(n,0);
        for(int j = 0; j < n; ++j) {
            ans[j] = ansInd[j].first;
        }
        return ans;
    }
};