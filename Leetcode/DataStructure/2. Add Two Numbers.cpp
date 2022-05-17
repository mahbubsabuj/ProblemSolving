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
    ListNode* add (ListNode* a, ListNode* b, int carry = 0) {
        if (a == NULL && b == NULL) {
            if (carry == 0) return NULL;
            return new ListNode(carry);
        };
        ListNode* head = new ListNode();
        if (a != NULL && b != NULL) {
            int sum = a->val + b->val + carry;
            carry = 0;
            if (sum >= 10) carry = 1;
            head->val = sum % 10;
            head->next = add(a->next, b->next, carry);
        }  else if (a != NULL) {
            int sum = a->val + carry;
            carry = 0;
            if (sum >= 10) carry = 1;
            head->val = sum % 10;
            head->next = add(a->next, b, carry);
        } else {
            int sum = b->val + carry;
            carry = 0;
            if (sum >= 10) carry = 1;
            head->val = sum % 10;
            head->next = add(a, b->next, carry);
        }
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);
    }
};