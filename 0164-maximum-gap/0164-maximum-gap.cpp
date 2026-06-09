class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        //making 10 buckets
        vector<queue<int>> buckets(19);

        //finding the max length of any number in nums
        int l = 0;
        for(int i = 0; i<n; ++i) {
            if(abs(nums[i]) > l) {
                l = abs(nums[i]);
            }
        }
        l = to_string(l).length();
        int cnt = 0;
        while(cnt < l) {
            for(int i : nums) {
                int t = 0, t1 = i;
                for(int k = 0; k <= cnt; ++k) {
                    t = i % 10;
                    i = i / 10;
                }
                buckets[t+9].push(t1);
            }
            vector<int> res;
            for(auto &it : buckets) {
                while(!it.empty()) {
                    res.push_back(it.front());
                    it.pop();
                }
            }
            for(int i = 0; i < n; ++i) {
                nums[i] = res[i];
            }
            cnt++;
        }

        int maxGap = 0;
        for(int i = 0; i < n-1; ++i) {
            maxGap = max(maxGap, nums[i+1] - nums[i]);
        }
        return maxGap;
    }
};