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
    int getLength(ListNode* head) {
        int length = 0;
        while (head != NULL) {
            head = head->next;
            ++length;
        }
        return length;
    }
    ListNode* middleNode(ListNode* head) {
        int middle = getLength(head) / 2 + 1;
        for (int i = 1; i < middle; ++i) {
            head = head->next;
        }
        return head;
    }
};