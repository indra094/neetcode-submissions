/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return NULL;
        }
        Node* node = head;
        while(node) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            newNode->random = node->random;
            node->next = newNode;
            node = newNode->next;
        }


        Node* newNode = head->next;
        while(newNode) {
            if(newNode->random) {
                newNode->random = newNode->random->next;
            }
            newNode = newNode->next;
            if(newNode) {
                newNode = newNode->next;
            }
        }

        Node* newHead = head->next;
        newNode = newHead;
        node = head;
        while(node) {
            node->next = newNode->next;
            node=node->next;
            if(node) {
                newNode->next = node->next;
            }
            newNode = newNode->next;
        }

        return newHead;
    }
};
