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

        // Base Case 1:
        // If list1 is empty, the head of the merged list
        // is simply list2.
        if (list1 == nullptr)
            return list2;

        // Base Case 2:
        // If list2 is empty, the head of the merged list
        // is simply list1.
        if (list2 == nullptr)
            return list1;

        // Compare the current (head) nodes of both lists.
        if (list1->val <= list2->val) {

            // The current node of list1 has the smaller
            // (or equal) value.
            //
            // Therefore THIS node becomes the head of the
            // merged list for the current recursive call.
            //
            // Example:
            // list1: 1 -> 2 -> 4
            // list2: 1 -> 3 -> 4
            //
            // Current head returned = first node from list1.

            list1->next = mergeTwoLists(list1->next, list2);

            // Return list1 because its current node is the head
            // of the merged list for this call.
            return list1;
        }

        // The current node of list2 has the smaller value.
        //
        // Therefore THIS node becomes the head of the
        // merged list for the current recursive call.
        //
        // Example:
        // list1: 2 -> 4
        // list2: 1 -> 3 -> 4
        //
        // Current head returned = first node from list2.

        list2->next = mergeTwoLists(list1, list2->next);

        // Return list2 because its current node is the head
        // of the merged list for this call.
        return list2;
    }
};