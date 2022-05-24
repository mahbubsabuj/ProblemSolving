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
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        
        if (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                ListNode* head = new ListNode(list1->val);
                head->next = mergeTwoLists(list1->next, list2);
                return head;
            } else {
                ListNode* head = new ListNode(list2->val);
                head->next = mergeTwoLists(list1, list2->next);
                return head;
            }
        } else if (list1 != NULL) {
            return list1;
        } else {
            return list2;
        }
    } 
};