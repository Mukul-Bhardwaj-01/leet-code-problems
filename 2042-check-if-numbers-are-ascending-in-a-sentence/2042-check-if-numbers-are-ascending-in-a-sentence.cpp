class Solution {
public:
    bool areNumbersAscending(string s) {
        vector<int> listOfNums;
        unordered_set<char> set = {'1','2','3','4','5','6','7','8','9','0'};
        int n = s.length();
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
                listOfNums.push_back(stoi(temp));
            }
        }
        for(int i = 0; i<listOfNums.size() - 1; ++i) {
            if(listOfNums[i] >= listOfNums[i+1]) return false;
        }
        return true;
    }
};