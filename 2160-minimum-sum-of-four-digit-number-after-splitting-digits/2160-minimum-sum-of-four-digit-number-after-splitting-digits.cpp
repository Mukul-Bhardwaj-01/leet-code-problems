class Solution {
public:
    int minimumSum(int num) {
        vector<int> numvec;
        while(num > 0) {
            numvec.push_back(num%10);
            num /= 10;
        }
        sort(numvec.begin(),numvec.end());
        int num1 = numvec[0] * 10 + numvec[2];
        int num2 = numvec[1] * 10 + numvec[3];
        
        return num1 + num2;
    }
};