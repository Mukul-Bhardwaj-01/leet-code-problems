class Solution {
public:
    string revInv(string str) {
        for(char&c : str) {
            if(c == '0') c='1';
            else c='0';
        }
        reverse(str.begin(),str.end());
        return str;
    }
    string constructSn(int n) {
        if(n==1) return "0";
        string prev = constructSn(n-1); 
        return prev + "1" + revInv(prev);
    }
    char findKthBit(int n, int k) {
        string s = constructSn(n);
        return s[k-1];
    }
};