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
    int get_gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* node1 = head, * node2 = head -> next;
        while(node2) {
            ListNode* node = new ListNode(get_gcd(node1 -> val, node2 -> val));
            node -> next = node1 -> next;
            node1 -> next = node;
            node1 = node2;
            node2 = node2 -> next;
        }
        return head;
    }
};