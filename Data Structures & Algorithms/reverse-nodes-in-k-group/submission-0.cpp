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
    ListNode* reverseKGroup(ListNode* head, int k) {

        // STEP 1: Check if there are at least k nodes ahead
        // We move curr pointer k steps forward
        ListNode* curr = head;
        int count = 0;

        while (curr != nullptr && count < k) {
            curr = curr->next;  // move forward one node
            count++;            // count how many nodes we saw
        }

        // If we found k nodes, we can reverse this segment
        if (count == k) {

            // STEP 2: Reverse first k nodes

            ListNode* prev = nullptr;   // will become new head of this segment
            ListNode* nextNode = nullptr;

            curr = head; // reset curr back to start of segment

            for (int i = 0; i < k; i++) {

                nextNode = curr->next; // store next node (important before breaking link)

                curr->next = prev;     // reverse pointer direction

                prev = curr;           // move prev forward
                curr = nextNode;       // move curr forward
            }

            // After loop:
            // prev = new head of reversed segment
            // curr = first node after reversed segment

            // STEP 3: Recursively process remaining list
            if (nextNode != nullptr) {
                // head is now the LAST node of reversed segment
                // connect it to the result of next reversed group
                head->next = reverseKGroup(nextNode, k);
            }

            // return new head of this reversed group
            return prev;
        }

        // If less than k nodes left, do NOT reverse
        // just return head as it is
        return head;
    }
};