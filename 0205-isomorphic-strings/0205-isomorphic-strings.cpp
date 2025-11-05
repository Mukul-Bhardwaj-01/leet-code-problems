class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int n = s.length();
        vector<int> sMap(128,-1), tMap(128,-1); //space O(256)
        for(int i = 0; i<n; ++i) {
            if(sMap[s[i]] == -1 && tMap[t[i]] == -1) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            }
            else if(sMap[s[i]] != t[i]) return 0;
        }
        return 1;
    }
};