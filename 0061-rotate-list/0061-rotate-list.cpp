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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        //count number of nodes n
        while(temp) {
            n++;
            if(temp -> next == nullptr) break;
            temp = temp -> next;
        }
        //find the effective number of rotations needed to be done
        if(k == 0 || n == 0) return head;
        k = k%n;
        //check for no rotations
        if(k == 0) return head;
        //make the LL circular
        temp -> next = head;
        //connect the current tail to the head and maintain a pointer to the original head and then just go to n - k - 1 th node and call it the newTail, its next will be the new head and then snap the newTail with the newHead and return newHead
        int newtailPos = n - k - 1;
        ListNode* newTail = head;
        int cnt = 0;
        while(cnt < newtailPos) {
            cnt++;
            newTail = newTail -> next;
        }
        ListNode* newHead = newTail -> next;
        newTail -> next = nullptr;
        return newHead;
    }
};