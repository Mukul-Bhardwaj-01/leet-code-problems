class Solution {
public:
    bool areNumbersAscending(string s) {
        unordered_set<char> set = {'1','2','3','4','5','6','7','8','9','0'};
        int n = s.length();
        int latest = INT_MIN;
        for(int i = 0; i<n; ++i) {
            if(set.count(s[i])) {
                int start = i, end;
                while(i < n && set.count(s[i])) {
                    i++;
                    end = i;
                } 
                string temp = "";
                for(int k = start; k <= end; ++k) {
                    temp += s[k];
                }
                if(latest < stoi(temp)) latest = stoi(temp);
                else return false;
            }
        }
        return true;
    }
};