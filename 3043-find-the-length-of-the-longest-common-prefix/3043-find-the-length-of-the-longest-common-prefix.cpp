class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for(int num : arr1) {
            while(num > 0) {
                s.insert(num);
                num /= 10;
            }
        }
        int ans = 0;
        for(int num : arr2) {
            int digits = to_string(num).length();
            if(digits <= ans) continue;
            while(num > 0) {
                if(s.count(num)) {
                    ans = max(ans,digits);
                    break;
                }
                num /= 10;
                digits--;
            }
        }
        return ans;
    }
};