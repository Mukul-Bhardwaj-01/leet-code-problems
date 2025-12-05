class Solution {
public:
    const long long mod = 1000000007;
    long long nC2(int n) {
        long long res = (1LL*n*(n-1)/2) % mod;
        return res;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> hash;
        for(const auto& it : points) {
            hash[it[1]]++;
        }
        vector<long long> seg;
        seg.reserve(hash.size());
        for(const auto& it : hash) {
            if(it.second >= 2) seg.push_back(nC2(it.second));
        }
        if(seg.size()<2) return 0;
        int n = seg.size();
        long long total = 0, sum = accumulate(seg.begin(),seg.end(),0LL) % mod;
        for(int i = 0; i<n-1; ++i) {
            sum = (sum - seg[i] + mod)%mod;
            total = (total + seg[i]*sum) % mod;
        }
        return (int)(total%mod);
    }
};