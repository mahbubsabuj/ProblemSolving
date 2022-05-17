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
    //brute
    bool hasCycle(ListNode *head) {
        int count = 0;
        while (head != NULL && count <= 10010) {
            head = head->next;
            ++count;
        }
        if (count > 10000) return true;
        return false;
    }
};