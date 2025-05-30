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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode*temp, *dummy;
        temp=head;
        while(temp!=NULL) {
            count++;
            temp= temp->next;
        }
        int m= count-n+1;
        dummy=head;
        if (m>1) {
            count=1;
            while(count<m-1) {
                dummy=dummy->next;
                count++;
            }
            dummy->next=dummy->next->next;
            return head;
        }
        else{
            return head->next;
        }
    }
};