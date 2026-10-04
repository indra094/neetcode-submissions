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

    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        ListNode* result=new ListNode();
        ListNode* node=result, *next=NULL;
        while(head1 && head2) {
            if(head1->val<=head2->val) {
                next = head1->next;
                node->next = head1;
                head1 = next;
            }
            else {
                next = head2->next;
                node->next = head2;
                head2 = next;
            }
            node = node->next;
        }
        if(head1) {
            node->next = head1;
        }
        else {
            node->next = head2;
        }

        return result->next;
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
        if(end-start+1==1) {
            return lists.at(start);
        }
        for(int offset=1; offset<lists.size(); offset<<=1) {
            for(int id=0; id<lists.size()-offset; id+=2*offset) {
                lists[id]=merge2Lists(lists[id], lists[id+offset]);
            }
        }
        
        return lists.front();
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return NULL;
        }
        if(lists.size()==1) {
            return lists.front();
        }

        return mergeLists(lists, 0, lists.size()-1);
    }
};
