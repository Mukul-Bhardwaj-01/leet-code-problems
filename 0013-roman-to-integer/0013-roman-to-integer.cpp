class Solution {
public:
    int romanToInt(string s) {
        int IntNum = 0, n = s.length();
        unordered_map<char,int> values = {{'I',1}, {'V',5}, {'X',10}, 
        {'L',50}, {'C',100}, {'D',500}, {'M',1000}}; 
        for(int i = 0; i<n; ++i) {
            if(i+1<n && values[s[i]]<values[s[i+1]]) {
                IntNum -= values[s[i]];
            }
            else IntNum += values[s[i]];
        }
        return IntNum;
    }
};