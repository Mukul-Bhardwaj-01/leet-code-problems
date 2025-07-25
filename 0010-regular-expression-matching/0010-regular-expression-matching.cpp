class Solution {
public:
    bool isMatch(string s, string p) {
        return match(0, 0, s, p);
    }

    unordered_map<string, bool> memo;

    bool match(int i, int j, string& s, string& p) {
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];

        if (j == p.length()) return memo[key] = (i == s.length());

        bool current_match = (i < s.length() && 
                              (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            return memo[key] = (match(i, j + 2, s, p) || 
                                (current_match && match(i + 1, j, s, p)));
        } else {
            return memo[key] = (current_match && match(i + 1, j + 1, s, p));
        }
    }
};