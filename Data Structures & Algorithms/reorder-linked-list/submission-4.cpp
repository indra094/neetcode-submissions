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
        if(!head || !head->next || !head->next->next) {
            return;
        }
        ListNode* slow=head, *fast=head;
        
        ListNode* prev=NULL;
        while(fast) {
            
            prev = slow;
            slow = slow->next;
            
            fast = fast->next;
            if(!fast) {
                break;
            }
            
            fast = fast->next;
            
        }
        

        prev->next = NULL;
        prev = NULL;
        ListNode* next=NULL;
        while(slow) {

            
            
            
            next = slow->next;
            
            
            slow->next = prev;
            prev = slow;
            slow = next;
            
            
        }
        
        
        slow = prev;
        //cout<<slow->next->val;

        ListNode* node=head, *next2=NULL;
        while(slow) {
            
            next = node->next;
            next2 = slow->next;
            
            node->next = slow;
            slow->next = next;
            node = next;
            slow = next2;
            
            
        }
        
        
    }
};
