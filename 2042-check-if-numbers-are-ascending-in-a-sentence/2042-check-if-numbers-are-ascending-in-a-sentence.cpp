class Solution {
public:
    bool areNumbersAscending(string s) {
        unordered_set<char> set = {'1','2','3','4','5','6','7','8','9','0'};
        int n = s.length();
        int latest = INT_MIN;
        for(int i = 0; i<n; ++i) {
            if(set.count(s[i])) {
                int start = i;
                while(i < n && set.count(s[i])) {
                    i++;
                } 
                int num = stoi(s.substr(start, i - start));
                if(latest < num) latest = num;
                else return false;
            }
        }
        return true;
    }
};