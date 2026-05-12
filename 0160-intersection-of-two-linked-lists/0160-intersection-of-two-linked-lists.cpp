/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists
        while (a != b) {
            // If a reaches end, move to headB
            a = (a == NULL) ? headB : a->next;

            // If b reaches end, move to headA
            b = (b == NULL) ? headA : b->next;
        }

        // Either intersection node or NULL
        return a;
    }
};