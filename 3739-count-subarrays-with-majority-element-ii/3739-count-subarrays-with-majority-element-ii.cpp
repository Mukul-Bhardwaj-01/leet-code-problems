#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // transform
        for (int &x : nums)
            x = (x == target) ? 1 : -1;

        ordered_set st;

        long long ans = 0;
        int prefix = 0;

        // prefix sum before array starts
        st.insert({0, -1});

        for (int i = 0; i < n; ++i) {
            prefix += nums[i];

            // number of previous prefix sums < current prefix sum
            ans += st.order_of_key({prefix, INT_MIN});

            st.insert({prefix, i});
        }

        return ans;
    }
};