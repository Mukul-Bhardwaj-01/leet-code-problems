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
        ListNode *cur1 = head, *cur2 = head;
        while(cur2) {
            n++;
            cur2 = cur2 -> next;
        }

        // Use a stack to store nodes from the n/2 th to the last node
        stack<ListNode*> s;
        int j = n / 2, i = 0;
        cur2 = head;
        while(i < j) {
            cur2 = cur2 -> next;
            i++;
        }
        while(cur2) {
            s.push(cur2);
            cur2 = cur2 -> next;
        }

        int ans = INT_MIN;
        while(!s.empty()) {
            ans = max(ans,cur1 -> val + s.top() -> val);
            cur1 = cur1 -> next;
            s.pop();
        }
        return ans;
    }
};