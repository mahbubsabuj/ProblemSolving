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
    ListNode* merge (priority_queue<pair<int, ListNode*>> &pq) {
        if (pq.empty()) return NULL;
        ListNode* top = pq.top().second;
        pq.pop();
        ListNode* root = new ListNode(top->val);
        if (top->next != NULL) pq.push(make_pair(-top->next->val, top->next));
        root->next = merge(pq);
        return root;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> pq;
        for (ListNode* node : lists) {
            if (node != NULL) {
                pq.push(make_pair(-node->val, node));
            }
        }
        return merge(pq);
    }
};