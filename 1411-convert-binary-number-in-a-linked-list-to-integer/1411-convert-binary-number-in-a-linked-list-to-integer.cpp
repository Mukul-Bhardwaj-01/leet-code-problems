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
    int power2(int n) {
        int res=1;
        for(int i=0;i<n;i++) {
            res=res*2;
        }
        return res;
    }
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode*A = head;
        while(!A==NULL) {
            n++;
            A=A->next;
        }
        if(n==0) return 0;
        int result=0;
        for(int i=n-1; i>=0; i--) {
            result+=power2(i)*(head->val);
            head=head->next;
        }
        return result;
    }
};