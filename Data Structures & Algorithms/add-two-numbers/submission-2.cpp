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
        ListNode *head=new ListNode(),*result=head, *node1=l1, *node2=l2;
        int carry = 0;
        while(node1 && node2) {
            int sum = node1->val+node2->val+carry;
            result->next = new ListNode(sum%10);
            carry = sum/10;
            result = result->next;
            node1 = node1->next;
            node2 = node2->next;
        }

        while(node1 && carry!=0) {
            int sum=node1->val+carry;
            carry = sum/10;
            result ->next = new ListNode(sum%10);
            result = result->next;
            node1 = node1->next;
        }

        while(node2 && carry!=0) {
            int sum=node2->val+carry;
            carry = sum/10;
            result ->next = new ListNode(sum%10);
            result = result->next;
            node2 = node2->next;
        }

        result->next=carry==1?(new ListNode(carry)):(node1?node1:node2);

        return head->next;
    }
};
