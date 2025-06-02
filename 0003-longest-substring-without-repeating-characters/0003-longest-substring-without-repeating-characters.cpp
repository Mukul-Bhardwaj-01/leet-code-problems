class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> chars;
            int count = 0;
            for (int j = i; j < s.length(); j++) {
                if (chars.count(s[j])) break;
                chars.insert(s[j]);
                count++;
            }
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};