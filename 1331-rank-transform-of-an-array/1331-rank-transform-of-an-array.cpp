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

        int temp = vecInd[0].first;
        vecInd[0].first = 1;
        int rank = 1;
        int i = 1;
        while(i < n) {
            if(vecInd[i].first == temp) {
                vecInd[i].first = rank;
            }
            else {
                rank++;
                temp = vecInd[i].first;
                vecInd[i].first = rank;
            }
            i++;
        }

        sort(vecInd.begin(),vecInd.end(),[] (const auto &a, const auto &b) {
            return a.second < b.second;
        });
        vector<int> ans(n,0);
        for(int j = 0; j < n; ++j) {
            ans[j] = vecInd[j].first;
        }
        return ans;
    }
};