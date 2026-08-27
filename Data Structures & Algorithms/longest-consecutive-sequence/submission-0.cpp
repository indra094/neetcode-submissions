class Solution {

    struct Node {
        int num;
        Node* prev=NULL;
        Node* next=NULL;
    };
public:

    int findChainLen(Node* node) {
        int len = 0;
        while(node) {
            len++;
            node=node->next;
        }
        return len;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, Node* > existing;
        for(int num:nums) {
            existing[num] = new Node();
            existing[num]->num = num;
            existing[num]->prev = NULL;
        }

        for(auto& entry:existing) {
            if(existing.contains(entry.first+1)) {
                entry.second->next = existing[entry.first+1];
                existing[entry.first+1]->prev = entry.second;
            }
        }

        int maxLen = 0;
        for(auto entry:existing) {
            if(entry.second->prev == NULL) {
                maxLen = max(maxLen, findChainLen(entry.second));
            }
        }
        return maxLen;
    }
};
