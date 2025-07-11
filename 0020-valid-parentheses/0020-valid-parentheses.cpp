class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 != 0) return false;
        stack<char> result;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                result.push(ch);
            }
            else {
                if (result.empty()) return false;
                char top = result.top();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    result.pop();
                } else {
                    return false;
                }
            }
        }
        return result.empty();
    }
};