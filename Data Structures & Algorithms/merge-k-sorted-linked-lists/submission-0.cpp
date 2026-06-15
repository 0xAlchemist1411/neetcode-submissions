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
        vector<int> vec;

        for(auto head: lists){
            ListNode* temp = head;
            while(temp){
                vec.push_back(temp->val);
                temp = temp->next;
            }
        }

        if (vec.empty()) {
            return nullptr;
        }

        sort(vec.begin(),vec.end());

        ListNode* head = new ListNode(vec[0]);  // first node
        ListNode* curr = head;

        for(int i=1;i<vec.size();i++){
            curr->next = new ListNode(vec[i]);  // create new node
            curr = curr->next;                     
        }

        return head;
    }
};












