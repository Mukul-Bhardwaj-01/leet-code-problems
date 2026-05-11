class Solution {
public:
    int minimumSum(int num) {
        vector<int> numvec;
        while(num > 0) {
            numvec.push_back(num%10);
            num /= 10;
        }
        sort(numvec.begin(),numvec.end());
        return (numvec[0] + numvec[1])*10 + numvec[2] + numvec[3];
    }
};