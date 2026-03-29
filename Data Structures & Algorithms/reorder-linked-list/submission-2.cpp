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
    void reorderList(ListNode* curr) {
        ListNode* fast = curr->next;
        ListNode* slow = curr;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = nullptr;

        slow->next = nullptr;

        while(second){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        while(prev){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = prev->next;
            curr->next = prev;
            prev->next = temp1;
            prev = temp2;
            curr = temp1;
        }
    }
};
