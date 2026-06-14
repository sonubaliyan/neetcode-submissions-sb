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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;

        ListNode *tmp = head;
        while(tmp)
        { 
            len++;
            tmp = tmp->next;
        }

        int pos = len - n;
        if (pos == 0) return head->next;

        ListNode *tmp2 = head;
        ListNode *prev = nullptr;
        while(pos)
        {   
            prev = tmp2;
            tmp2 = tmp2->next;
            pos--;
        }

        prev->next = tmp2->next;

        return head;
        
    }
};