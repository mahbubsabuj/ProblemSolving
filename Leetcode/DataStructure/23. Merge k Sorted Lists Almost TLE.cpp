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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int nullCount = 0;
        int minVal = INT_MAX;
        int minIdx = -1;
        for (int i = 0; i < (int) lists.size(); ++i) {
            if (lists[i] == NULL) ++nullCount;
            if (lists[i] != NULL) {
                if (minVal > lists[i]->val) {
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }
        }
        if ((int) lists.size() == nullCount) return NULL;
        ListNode* root = new ListNode(minVal);
        lists[minIdx] = lists[minIdx]->next;
        root->next = mergeKLists(lists);
        return root;
    }
};