class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int k = 0, n = words.size();
        while(k < n) {
            if(words[k] == target) {
                int dist = abs(k - startIndex);
                dist = min(dist, n - dist);
                ans = min(ans, dist);
            }
            k++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};