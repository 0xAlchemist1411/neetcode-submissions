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
        // Step 1: find length of linked list
        int l = 0;
        ListNode* curr = head;
        while (curr) {
            l++;
            curr = curr->next;
        }

        // Step 2: if we need to remove the first node
        if (n == l) {
            return head->next;
        }

        // Step 3: go to the (l - n - 1)th node
        curr = head;
        for (int i = 0; i < l - n - 1; i++) {
            curr = curr->next;
        }

        // Step 4: skip the nth node from end
        curr->next = curr->next->next;

        // Step 5: return head
        return head;
    }
};
