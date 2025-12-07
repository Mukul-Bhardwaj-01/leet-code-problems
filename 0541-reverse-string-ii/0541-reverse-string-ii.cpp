class Solution {
public:
    string reverseStr(string s, int k) {
        vector<string> st;
        int sets = (s.length() + (2*k) - 1)/(2*k);
        for(int i = 0; i<sets; ++i) {
            string temp = "";
            for(int j = 0; j<2*k; ++j) {
                if(j + i*2*k > s.length()-1) break; 
                temp += s[j + i*2*k];
            }
            st.push_back(temp);
        }
        for(string &str : st) {
            if(str.length() <= k) reverse(str.begin(),str.end());
            else reverse(str.begin(),str.begin()+k);
        }
        string res = "";
        for(string str: st) res+=str;
        return res;
    }
};