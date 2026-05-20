class Solution {
public:
    int countCommons(vector<int>& A, vector<int>& B, int i) {
        unordered_set<int> setOfA;
        for(int k = 0; k<=i; ++k) {
            setOfA.insert(A[k]);
        }
        int cnt = 0;
        for(int k = 0; k<=i; ++k) {
            if(setOfA.count(B[k])) cnt++;
        }
        return cnt;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n,0);
        for(int i = 0; i<n; ++i) {
            C[i] = countCommons(A,B,i);
        }
        return C;
    }
};