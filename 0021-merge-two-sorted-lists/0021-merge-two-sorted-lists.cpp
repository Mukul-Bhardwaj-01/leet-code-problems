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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* cur1 = list1, *cur2 = list2, *resultHead;
        if(cur1 -> val <= cur2 -> val) {
            resultHead = cur1;
            cur1 = cur1 -> next;
        }
        else {
            resultHead = cur2;
            cur2 = cur2 -> next;
        }
        ListNode* curr = resultHead;
        while(cur1 && cur2) {
            if(cur1 -> val <= cur2 -> val) {
                curr -> next = cur1;
                curr = curr -> next;
                cur1 = cur1 -> next;
            }
            else {
                curr -> next = cur2;
                curr = curr -> next;
                cur2 = cur2 -> next;
            }
        }
        while(cur1) {
            curr -> next = cur1;
            curr = curr -> next;
            cur1 = cur1 -> next;
        }
        while(cur2) {
            curr -> next = cur2;
            curr = curr -> next;
            cur2 = cur2 -> next;
        }
        curr -> next = nullptr;
        return resultHead;
    }
};