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
        ListNode dummy(0);
        ListNode* head = &dummy;
        if (lists.size() == 0) return head->next;
        bool br = false;
        while(! br){
            br = true;
            int min = INT_MAX;
            ListNode* minptr;
            for(int i = 0; i < lists.size(); i++){
                if (! lists[i]) continue;
                if (min > lists[i]->val){
                    min = lists[i]->val;
                    minptr = lists[i];
                }
            }
            head->next = minptr;
            head = head->next;
            
            for(int i = 0; i < lists.size(); i++){
                if (lists[i] && lists[i] == minptr) lists[i] = lists[i]->next;
                if (lists[i] && lists[i] != nullptr) br = false;
            }
            // cout << head->next << endl;
        }

        head = &dummy;
        return head->next;
    }
};
