class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        long long len = 1;
        lengths.push_back(len);
        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }
        char c = 'a';
        for (int i = lengths.size() - 2; i >= 0; --i) {
            long long half = lengths[i];
            if (k > half) {
                k -= half;
                if (operations[i] == 1) {
                    c = (c == 'z') ? 'a' : c + 1;
                }
            }
        }
        return c;
    }
};