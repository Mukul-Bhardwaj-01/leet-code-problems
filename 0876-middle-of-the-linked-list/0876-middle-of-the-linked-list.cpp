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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur = head;
        int n = 0;
        while(cur) {
            n++;
            cur = cur -> next;
        }
        int mid = n/2, i = 0;
        cur = head;
        while(i < mid) {
            i++;
            cur = cur -> next;
        }
        return cur;
    }
};