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
        //stack to store nodes which are to be moved to the front
        stack<ListNode*> s;

        ListNode* temp2 = head;
        //number of nodes that stay as is and not needed to be pushed into the stack
        int asIs = n - k;
        int cnt = 0;
        while(cnt < asIs - 1) {
            cnt++;
            temp2 = temp2 -> next;
        }
        ListNode* newHead = temp2 -> next;
        temp2 -> next = nullptr;
        //temp2 now points to the last node of the final linked list
        //newHead stores the elements which need to be moved to the front and thus before that to be pushed into the stack
        while(newHead) {
            s.push(newHead);
            newHead = newHead -> next;
        }
        //finally newHead is at NULL and now we have a linked list with last k elements missing and those are stored in the stack.
        //now we will do the operation of pop from stack and make it the new head and connect with the current head of the list until the stack is empty
        ListNode* tempHead = head;
        while(!s.empty()) {
            ListNode* LN1 = s.top();
            s.pop();
            ListNode* currentHead = tempHead;
            tempHead = LN1;
            tempHead -> next = currentHead;
        }
        return tempHead;
    }
};