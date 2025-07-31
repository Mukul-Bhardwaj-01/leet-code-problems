class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;        // Final set of all unique ORs
        unordered_set<int> prev;          // ORs ending at previous index

        for (int num : arr) {
            unordered_set<int> cur;       // ORs ending at current index

            // For each OR from previous, OR with current number
            for (int x : prev) {
                cur.insert(x | num);
            }

            // Also include the number itself (new subarray)
            cur.insert(num);

            // Add all current ORs to result set
            for (int x : cur) {
                result.insert(x);
            }

            // Update prev to current for next iteration
            prev = cur;
        }

        return result.size();
    }
};
