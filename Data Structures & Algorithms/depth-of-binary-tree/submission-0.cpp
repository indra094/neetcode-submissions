/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    void traverse(TreeNode* node, int depth, int& maxDepth) {
        maxDepth = max(maxDepth, depth);
        if(node->left) {
            traverse(node->left, depth+1, maxDepth);
        }
        if(node->right) {
            traverse(node->right, depth+1, maxDepth);
        }
    }

public:
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        if(!root) {
            return 0;
        }
        traverse(root, 1, maxDepth);

        return maxDepth;
        
    }
};
