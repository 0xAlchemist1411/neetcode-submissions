class Solution {
private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;  // not enough nodes left to reverse

            ListNode* groupNext = kth->next;

            // Reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group
            ListNode* temp = groupPrev->next;  // this is the new tail after reversal
            groupPrev->next = kth;             // connect previous part to new head
            groupPrev = temp;                  // move groupPrev to tail for next iteration
        }

        return dummy.next;
    }
};
