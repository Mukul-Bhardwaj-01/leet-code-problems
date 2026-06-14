/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // Count number of nodes in the linked list
        int n = 0;
        ListNode *cur = head, *prev = nullptr;
        while(cur) {
            n++;
            cur = cur -> next;
        }

        // Make cur node point to the (n/2 - 1)th node
        cur = head;
        int j = n/2 - 1, i = 0;
        while(i < j) {
            cur = cur -> next;
            i++;
        }

        // Reversing LL in-place using curr, prev and nxt pointers
        ListNode* curr = cur -> next;
        while(curr) {
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        cur -> next = prev;
        // Now, curr is nullptr, prev is the new head upon 2nd half reversal and is the n/2 th node

        int ans = INT_MIN;
        cur = head;
        // cur starts off at head and prev at n/2th node, and keep on comparing sum with ans
        while(prev) {
            ans = max(ans,cur -> val + prev -> val);
            cur = cur -> next;
            prev = prev -> next;
        }
        return ans;
    }
};