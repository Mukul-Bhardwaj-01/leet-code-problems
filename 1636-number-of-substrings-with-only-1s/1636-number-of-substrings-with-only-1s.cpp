class Solution {
public:
    long long substrCount(int length) {
        long long num = 0;
        for(int i = 0; i<length; ++i) {
            for(int j = i; j<length; ++j) num++;
        }
        return num;
    }
    int numSub(string s) {
        long long count = 0; int length = 0;
        for(char c : s) {
            if(c=='1') length++;
            else if(length!=0) {
                count+=substrCount(length);
                length=0;
            }
        }
        if(length!=0) count+=substrCount(length);
        return count%(1000000007);
    }
};