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

    ListNode* kth(ListNode* curr , int k){
        while(curr && k){
            curr = curr->next;
            k--;
        }

        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head); 
        ListNode* curr = head;
        ListNode* group = dummy;
        ListNode* tail = head;
        
        while(true){
            ListNode* k = kth(group, n);

            if (!k) break;
            // enough elements exist
            ListNode* next = k->next;

            ListNode* prev = k->next;
            ListNode* curr = group->next;
            while(curr != next){
                ListNode* t = curr->next;
                curr->next = prev;
                prev = curr;
                curr = t;
            }

            ListNode* tmp = group->next;
            group->next = k;
            group = tmp;
        }

        return dummy->next;
    }
};
