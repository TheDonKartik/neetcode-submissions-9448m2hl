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
        int size = 1;
        ListNode* curr = head;

        while(curr->next){
            size++;
            curr=curr->next;
        }
        if (n == size) return head->next;

        ListNode* prev = head;
        
        for(int i = 1; i < size-n; i++){
            prev = prev->next;
        }
        curr = prev->next->next;
        prev->next = curr;
        return head;
    }
};
