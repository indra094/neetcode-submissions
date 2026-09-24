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
    bool hasCycle(ListNode* head) {
        if(!head) {
            return false;
        }
        ListNode* fast=head,*slow=head;
        fast=fast->next;
        while(fast) {
            if(fast == slow) {
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
        }

        return false;
    }
};
