class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> seen(n,false);
        q.push(start);
        seen[start] = true;
        while(!q.empty()) {
            int ind = q.front();
            q.pop();
            if(arr[ind] == 0) return true;
            int left = ind - arr[ind];
            int right = ind + arr[ind];
            if(left >= 0 && !seen[left]) {
                q.push(left);
                seen[left] = true;
            }
            if(right < n && !seen[right]) {    
                q.push(right);
                seen[right] = true;
            }
        }
        return false;
    }
};