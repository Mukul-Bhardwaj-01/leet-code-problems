class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int d = arr[1] - arr[0];
        int n = arr.size();
        
        //finding the correct value of d
        for(int i = 0; i<n-1; ++i) {
            d = min(d,arr[i+1] - arr[i]);
        }

        //storing all pairs having difference d
        for(int i = 0; i<n-1; ++i) {
            if(arr[i+1] - arr[i] == d) {
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};