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
        int len=0;
        if(!head) {
            return head;
        }
        ListNode* node = head;
        while(node) {
            len++;
            node = node->next;
        }

        n=len-n+1;
        if(n==1) {
            return head->next;
        }
        len = 0;
        node = head;
        while(node) {
            len++;
            if(len==n-1) {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return head;
    }
};
