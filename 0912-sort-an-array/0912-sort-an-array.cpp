class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //making 10 buckets
        vector<queue<int>> buckets(19);

        //finding the max length of any number in nums
        int l = 0;
        for(int i = 0; i<nums.size(); ++i) {
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
            for(int i = 0; i < nums.size(); ++i) {
                nums[i] = res[i];
            }
            cnt++;
        }
        return nums;
    }
};