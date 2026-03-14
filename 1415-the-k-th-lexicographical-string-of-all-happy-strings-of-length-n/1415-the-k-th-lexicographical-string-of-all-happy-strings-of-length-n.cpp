class Solution {
public:
    string ans = "";
    int count = 0;
    void dfs(string &curr, int n, int k) {
        if(curr.size() == n) {
            count++;
            if(count == k) ans = curr;
            return;
        }
        for(char c = 'a'; c <= 'c'; c++) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                dfs(curr, n, k);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        dfs(curr, n, k);
        return ans;
    }
};