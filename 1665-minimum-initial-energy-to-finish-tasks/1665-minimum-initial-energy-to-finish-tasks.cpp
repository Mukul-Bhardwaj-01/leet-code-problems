class Solution {
public:
    bool check(vector<vector<int>>& tasks, int initEnergy) {
        for(auto &task : tasks) {
            if(task[1] > initEnergy) return false;
            initEnergy -= task[0];
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(), [] (const auto &vec1, const auto &vec2) {
            return vec1[1] - vec1[0] > vec2[1] - vec2[0];
        });
        int low = 1;
        int high = 0;
        for(auto &vec : tasks) {
            high += vec[1];
        }
        while(low <= high) {
            int mid = low + (high - low)/2;
            bool res = check(tasks, mid);
            if(res) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
/*
{1,3} {2,4} {8,9} {10,11} {10,12}
low = 1, high = 39
1st pass (1 <= 39)      2nd pass (21 <= 39)     3rd pass (31 <= 39)     4th pass (31 <= 34)
mid = 20                mid = 30                mid = 35                mid = 32
false                   false                   true                    false(wrong)               
low = 21                low = 31                high = 34
*/