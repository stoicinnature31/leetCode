/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // If the current node is null or the current node's value is the one we're looking for, return it
        if (root == NULL || root->val == val)
            return root;

        // If the value we're looking for is less than the current node's value, search in the left subtree
        if (val < root->val)
            return searchBST(root->left, val);
        else // Otherwise, search in the right subtree
            return searchBST(root->right, val);
    }
};
