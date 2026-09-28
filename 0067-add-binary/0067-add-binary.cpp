class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false; // represents whether carry bit exists or not
        vector<char> ans(max(a.length(),b.length()) + 1,'0'); // To return final answer
        int i = a.length()-1; // index referring to the LSB of a
        int j = b.length()-1; // index referring to the LSB of b
        int k = ans.size()-1; // index at which we need to store the value of a[i] + b[j] + carry
        while(i >= 0 && j >= 0) {
            if(a[i] - '0' && b[j] - '0') {
                if(carry) ans[k] = '1';
                else {
                    carry = true;
                }
            }
            else if(a[i] - '0' || b[j] - '0') {
                if(carry);
                else ans[k] = '1';
            }
            else {
                if(carry) {
                    ans[k] = '1';
                    carry = false;
                }
                else;
            }
            k--;i--; j--;
        }
        while(i >= 0) {
            if(a[i] - '0') {
                if(carry);
                else ans[k] = '1';
            }
            else {
                if(carry) {
                    ans[k] = '1';
                    carry = false;
                }
                else;
            }
            k--;i--;
        }
        while(j >= 0) {
            if(b[j] - '0') {
                if(carry);
                else ans[k] = '1';
            }
            else {
                if(carry) {
                    ans[k] = '1';
                    carry = false;
                }
                else;
            }
            k--;j--;
        }
        if(carry) ans[0] = '1';
        string res = "";
        if(ans[0] - '0') res += ans[0];
        for(int t = 1; t < ans.size(); ++t) {
            res += ans[t];
        }
        return res;
    }
};