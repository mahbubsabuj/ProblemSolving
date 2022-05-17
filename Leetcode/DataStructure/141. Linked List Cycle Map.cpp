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
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> has;
        while (head != NULL) {
            if (has.find(head) != has.end()) return true;
            has[head] = true;
            head = head->next;
        }
        return false;
    }
};