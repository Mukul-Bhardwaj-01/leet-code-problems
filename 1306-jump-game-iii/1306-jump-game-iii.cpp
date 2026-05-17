class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        unordered_set<int> seen;
        q.push(start);
        seen.insert(start);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i<size; ++i) {
                int ind = q.front();
                q.pop();
                if(arr[ind] == 0) return true;
                if(ind - arr[ind] >= 0) {
                    if(!seen.count(ind - arr[ind])) {
                        q.push(ind - arr[ind]);
                        seen.insert(ind - arr[ind]);
                    }
                }
                if(ind + arr[ind] < n) {
                    if(!seen.count(ind + arr[ind])) {
                        q.push(ind + arr[ind]);
                        seen.insert(ind + arr[ind]);
                    }
                }
            }
        }
        return false;
    }
};