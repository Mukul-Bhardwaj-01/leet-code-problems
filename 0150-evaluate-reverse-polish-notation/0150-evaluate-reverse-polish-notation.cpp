class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;        
        for (const string& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                switch (token[0]) {
                    case '+': s.push(a + b); break;
                    case '-': s.push(a - b); break;
                    case '*': s.push(a * b); break;
                    case '/': s.push(a / b); break;
                }
            }
            else s.push(stoi(token));
        }
        return s.top();
    }
};