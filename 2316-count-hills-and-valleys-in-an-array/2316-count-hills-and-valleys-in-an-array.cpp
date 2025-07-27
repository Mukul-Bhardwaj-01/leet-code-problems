class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0, n=nums.size();
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1]) continue;
            int prev = i - 1, next = i + 1;
            while (prev >= 0 && nums[prev] == nums[i]) prev--;
            while (next < n && nums[next] == nums[i]) next++;
            if (prev >= 0 && next < n) {
                if (nums[i] > nums[prev] && nums[i] > nums[next]) count++;
                else if (nums[i] < nums[prev] && nums[i] < nums[next]) count++;
            }
        }
        return count;
    }
};