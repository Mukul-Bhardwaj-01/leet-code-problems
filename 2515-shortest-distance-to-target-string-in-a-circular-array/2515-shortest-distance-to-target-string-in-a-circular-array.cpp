class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int k = 0, n = words.size();
        if(words[startIndex] == target) return k;
        //find in the front
        while(k<n-1) {
            if(words[(startIndex + 1 + k) % n] == target) {
                ans = k + 1;
                break;
            }
            k++;
        }
        int l = 0;
        //find in the back
        while(l<n-1) {
            if(words[(startIndex - 1 - l + n) % n] == target) {
                ans = min(ans, l + 1);
                break;
            }
            l++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};