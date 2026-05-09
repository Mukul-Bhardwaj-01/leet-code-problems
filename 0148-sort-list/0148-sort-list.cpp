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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        vector<ListNode*> llist;
        ListNode * curr = head;
        while(curr) {
            llist.push_back(curr);
            curr = curr -> next;
        }
        sort(llist.begin(),llist.end(), [] (const auto node1, const auto node2) {
            return node1 -> val < node2 -> val;
        });
        ListNode* newHead = llist[0];
        ListNode* temp = llist[0];
        for(int i = 1; i<llist.size(); ++i) {
            temp -> next = llist[i];
            temp = temp -> next;
        }
        temp -> next = nullptr;
        return newHead;
    }
};