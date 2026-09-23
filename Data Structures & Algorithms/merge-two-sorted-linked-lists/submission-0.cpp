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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(), *node3=list3;
        while(list1 || list2) {
            if(list1 == NULL) {
                node3->next = list2;
                node3=node3->next;
                list2=list2->next;
                continue;
            }

            if(list2 == NULL || list1->val<list2->val) {
                node3->next = list1;
                node3=node3->next;
                list1 = list1->next;
                continue;
            }

            node3->next = list2;
            node3=node3->next;
            list2=list2->next;
        }


        return list3->next;
    }
};
