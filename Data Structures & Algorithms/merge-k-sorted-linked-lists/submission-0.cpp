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
        
        // Min-heap (priority queue) that always keeps the smallest node on top
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // reverse order -> makes it min-heap
        };

        priority_queue<
            ListNode*,                  // what we store (node pointers)
            vector<ListNode*>,          // internal container
            decltype(cmp)               // comparator type (lambda type)
        > pq(cmp);

        // Step 1: push the HEAD node of each linked list into heap
        for (auto list : lists) {
            if (list) {
                pq.push(list); // only push if list is not empty (not nullptr)
            }
        }

        // Step 2: dummy node to simplify building result list
        ListNode dummy(0);
        ListNode* tail = &dummy;  // tail always points to last node in result

        // Step 3: process heap until empty
        while (!pq.empty()) {

            // get smallest current node among all lists
            ListNode* node = pq.top();
            pq.pop();

            // attach this node to result list
            tail->next = node;

            // move tail forward
            tail = tail->next;

            // IMPORTANT:
            // if this node has a next element in its own list,
            // push that next node into heap
            if (node->next) {
                pq.push(node->next);
            }
        }

        // Step 4: skip dummy node and return real head
        return dummy.next;
    }
};