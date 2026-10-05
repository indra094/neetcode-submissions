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
    int diam=0;

    int traverse(TreeNode* node) {
        int maxLen=0;
        int lLen=0, rLen=0;
        if(node->left) {
            lLen = 1+traverse(node->left);
        }
        if(node->right) {
            rLen = 1+traverse(node->right);
        }
        diam = max(diam, lLen+rLen);
        maxLen = max(rLen, lLen);

        return maxLen;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        diam = max(diam, traverse(root));
        return diam;
    }
};
