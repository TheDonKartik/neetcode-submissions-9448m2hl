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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* last;
        int size = 0;

        while(head->next){
            size++;
            head = head -> next;
        }

        last = head;
        head = curr;

        while(size > 1){
            curr->next = last;
            last->next = next;

            curr = next;
            next = curr->next;
            last = curr;
            size -= 2;

            for (int i = 0; i < size; i++) last = last->next;
        }
        
        if(size) next->next = nullptr;
        else curr->next = nullptr;
    }
};
