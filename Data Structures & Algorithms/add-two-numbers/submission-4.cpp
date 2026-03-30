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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        while(l1 && l2){
            int t = l1->val + l2->val;
            if(t < 10) l1->val = t;
            else{
                l1->val = t%10;
                if (l1->next) l1->next->val +=1;
                else { // l1 is finished
                    if(l2->next) { // add to l2
                        l1->next = l2->next;
                        if(l2->next->val < 9) {
                            l2->next->val +=1;
                            return head;
                        }
                        while(true){ // last value of l2 is 9
                            if(l2->next){ 
                                l2 = l2->next;
                                if (l2->val == 9) l2->val = 0;
                                else {
                                    l2->val += 1;
                                    return head;
                                }
                            } else {
                                ListNode* newNode = new ListNode(1);
                                l2->next = newNode;
                                return head;
                            }
                        }
                    }else { // l2 is also finished
                        ListNode* newNode = new ListNode(1);
                        l1->next = newNode;
                        return head;
                    }                
                }
            }
            if (! l1->next){
                l1->next = l2->next;  
                return head;
            } 
            l1 = l1->next;
            l2 = l2->next;
        }

        // l2 is finished but l1 is not
        while( l1 && l1->val > 9){
            l1->val = 0;
            if(l1->next) l1->next->val += 1;
            else{
                ListNode* newNode = new ListNode(1);
                l1->next = newNode;   
                break;             
            }
            l1 = l1->next;
        }

        // l1 is finished but l2 is not
        // if (l2) l1->next = l2;
        return head;
    }
};
