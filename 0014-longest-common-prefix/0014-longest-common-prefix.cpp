class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int minind=0;
        int n=strs.size();
        for (int i=0; i<n; i++) {
            if(strs[i]=="") return "";
            if(strs[i].length()<strs[minind].length())
                minind=i;
            }
        int m = strs[minind].length();
        for(int i=0; i<m; i++) {
            char c= strs[0][i];
            for(int j=1; j<n; j++) {
                if (strs[j][i]==c) continue;
                else return result;
            }
            result+=c;
        }
        return result;
    }
};